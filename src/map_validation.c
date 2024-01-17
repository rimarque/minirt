/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:07:10 by bde-sous          #+#    #+#             */
/*   Updated: 2024/01/17 22:20:56 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_validation.h"
#include <stdlib.h>


/*bool check_ambient_ratio(float ratio)
{
    return (ratio >=  0 && ratio <= 1);
} */

int	ft_freedoublepointer(char **dptr)
{
	int	i;

	i = 0;
	while (dptr[i])
	{
		free(dptr[i]);
		i++;
	}
	free(dptr);
    return(1);
}

int float_in_range(float value, float min, float max)
{
    return(value >= min && value <= max);
}

int	ft_ischar(const char *str, int val)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0 || ft_strlen(str) > 3)
		return (0);
	while (str[i] >= '0' && str[i] <= '5')
		i++;
	if (str[i] != '\0')
		return (0);
    val = ft_atoi(str);
	if (val > 255 || val < 0)
		return (0);
	return (1);
}

int	ft_isfloat(const char *str, float *val, int normalized)
{
	int	i;
    int flag;

    flag = 0;
	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
    if (str[0] == '-')
            i++;
	while (((str[i] >= '0' && str[i] <= '9') || str[i] == '.') && flag < 2)
    {
        if (str[i] == '.')
            flag++;
        i++;
    }
	if (str[i] != '\0')
		return (0);
    *val = ft_atof(str);
    if (normalized && (!float_in_range(*val, -1, 1)))
        return (0);
    return (1);
}

int parse_color(char *str, t_rgb *rgb)
{
    char    **raw;
    uint8_t irgb[3];
    int     i;

    i = 0;
    raw = ft_split(str,',');
    while(ft_arrlen(raw) == 3 && i < 3)
    {
        if (ft_ischar(raw[i], irgb[i]))
            i++;
        else
            return(0);
    }
    if(ft_arrlen(raw) != 3)
        return(0);
    rgb->r=irgb[0];
    rgb->g=irgb[1];
    rgb->b=irgb[2];
    ft_freedoublepointer(raw);
    return(1);
}

int parse_vec3(char *str, t_vec3 *vec, int normalized)
{
    char    **raw;
    float ivec[3];
    int     i;

    i = 0;
    vec = ft_calloc(1,sizeof(t_vec3));
    if(vec == NULL)
        return(0);
    raw = ft_split(str,',');
    while(ft_arrlen(raw) == 3 && i < 3)
    {
        if (ft_isfloat(raw[i], &ivec[i], normalized))
            i++;
        else
            return(0);
    }
    if (ft_arrlen(raw) != 3)
        return(0);
    vec->x=ivec[0];
    vec->y=ivec[1];
    vec->z=ivec[2];
    ft_freedoublepointer(raw);
    return(1);
}

int validate_A(char **line, t_scene *scene)
{
    if (ft_arrlen(line) == 3 && scene->amb == NULL)
    {
        scene->amb = malloc(sizeof(t_amb));
        if (scene->amb == NULL)
            return 0;
        scene->amb->ratio = ft_atof(line[1]);
        if (!parse_color(line[2], &scene->amb->color))
            return(0);
        if (!(float_in_range(scene->amb->ratio, 0, 1)) || !ft_isdigit(line[1][0]))
            return(0);
        return(1);
    }
    ft_freedoublepointer(line);
    return(0);
}

int validate_C(char **line, t_scene *scene)
{
    if (ft_arrlen(line) == 4 && scene->cam == NULL)
    {
        scene->cam = ft_calloc(1,sizeof(t_cam));
        if (scene->cam == NULL)
            return(0);
        if (!parse_vec3(line[1], &scene->cam->view_point, 0))
            return(0);
        if (!parse_vec3(line[2], &scene->cam->normal, 1))
            return(0);
        if (!ft_isfloat(line[3],&scene->cam->fov_x, 0))
            return(0);
        if (!(float_in_range(scene->cam->fov_x, 0, 180)) || !ft_isdigit(line[3][0]))
            return(0);
        scene->cam->fov_x = scene->cam->fov_x * (M_PI / 180);
        return(1);
    }
    ft_freedoublepointer(line);
    return(0);
}

int validate_L(char **line, t_scene *scene)
{
    if (ft_arrlen(line) == 4 && scene->light == NULL)
    {
        scene->light = ft_calloc(1,sizeof(t_light));
        if (!parse_vec3(line[1], &scene->light->point, 0))
            return(0);
        if (!ft_isfloat(line[2],&scene->light->ratio, 0))
            return(0);
        if (!(float_in_range(scene->light->ratio, 0, 1)) || !ft_isdigit(line[2][0]))
            return(0);
        return(1);
    }
    ft_freedoublepointer(line);
    return(0);
}

int validate_sp(char **line, t_obj *obj)
{
    if (ft_arrlen(line) == 4)
    {
        if (!parse_vec3(line[1], &obj->point, 0))
            return(0);
        if (!ft_isfloat(line[2], &obj->d, 0))
            return(0);
        if (!parse_color(line[3], &obj->color))
            return(0);
        obj->type = 1;
        return(1);
    }
    ft_freedoublepointer(line);
    return(0);
}

int validate_cy(char **line, t_obj *obj)
{
    if (ft_arrlen(line) == 6)
    {
        if (!parse_vec3(line[1], &obj->point, 0))
            return(0);
        if (!parse_vec3(line[2], &obj->normal, 1))
            return(0);
        if (!ft_isfloat(line[3], &obj->d, 0))
            return(0);
        if (!ft_isfloat(line[4], &obj->h, 0))
            return(0);
        if (!parse_color(line[5], &obj->color))
            return(0);
        return(1);
    }
    ft_freedoublepointer(line);
    return(0);
}

int validate_pl(char **line, t_obj *obj)
{
    if (ft_arrlen(line) == 4)
    {
        if (!parse_vec3(line[1], &obj->point, 0))
            return(0);
        if (!parse_vec3(line[2], &obj->normal, 1))
            return(0);
        if (!parse_color(line[3], &obj->color))
            return(0);
        return(1);
    }
    ft_freedoublepointer(line);
    return(0);
}

int addNode(char *str, t_obj_list **head) 
{
    t_obj_list *node;

    node = (t_obj_list *)malloc(sizeof(t_obj_list));
    if (node == NULL)
    {
        free(str);
        return(0);
    } 
    node->obj = ft_strdup(str);
    node->next = *head;
    *head = node;
    free(str);
    return(1);
}

int validate_line(char *line, t_scene *scene)
{
    char **words;

    if (!line)
        return(0);
    words = ft_split(line, ' ');
    if (ft_strlen(words[0]) == 1 && !ft_strcmp(words[0], "A"))
        return(validate_A(words, scene) & ft_freedoublepointer(words));
    if (ft_strlen(words[0]) == 1 && !ft_strcmp(words[0], "C"))
        return(validate_C(words, scene) & ft_freedoublepointer(words));
    if (ft_strlen(words[0]) == 1 && !ft_strcmp(words[0], "L"))
        return(validate_L(words, scene) & ft_freedoublepointer(words));
    if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "sp"))
        return(addNode(line, &scene->temp) & ft_freedoublepointer(words));
    if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "pl"))
        return(addNode(line, &scene->temp) & ft_freedoublepointer(words));
    if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "cy"))
        return(addNode(line, &scene->temp) & ft_freedoublepointer(words));
    if (words[0][0] == 10)
    {
        ft_freedoublepointer(words);
        return(1);
    }
    ft_freedoublepointer(words);
    return(0);
}

int	ft_stack_length(t_obj_list *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int validate_obj(char *line, t_obj *obj)
{
    char **words;

    if (!line)
        return(0);
    words = ft_split(line, ' ');
    if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "sp"))
        return(validate_sp(words, obj) & ft_freedoublepointer(words));
    if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "pl"))
        return(validate_pl(words, obj) & ft_freedoublepointer(words));
    if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "cy"))
        return(validate_cy(words, obj) & ft_freedoublepointer(words));
    if (words[0][0] == 10)
    {
        ft_freedoublepointer(words);
        return(1);
    }
    ft_freedoublepointer(words);
    return(0);
}

int list_to_obj(t_scene *scene)
{
    t_obj_list *head;
    int i;
    int erro;

    if(ft_stack_length(scene->temp) == 0)
        return(0);
    scene->obj = (t_obj *)malloc(sizeof(t_obj) * ft_stack_length(scene->temp));
    head = scene->temp;
    i = -1;
    while (head != NULL)
    {
        erro = validate_obj(head->obj, &scene->obj[++i]);
        if (erro == 0)
        {
            ft_putstr_fd("Invalid Map\n",2);
            return(0);
        }
        head = head->next;
    }
    return(1);
}

void init_scene(t_scene *scene)
{
    scene->amb = NULL;
    scene->cam = NULL;
    scene->light = NULL;
    scene->obj = NULL;
    scene->temp = NULL;
}

int map_validate(char *file, t_scene *scene)
{
    int     fd; 
    char    *line;

    fd = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
		return (127);
    line = ft_strtrimall(get_next_line(fd, 0));
    while (line)
    {
        if(!validate_line(line, scene))
        {
            free(line);
            ft_putstr_fd("Invalid Map\n",2);
            break;
        }
        else
            free(line);
        line = ft_strtrimall(get_next_line(fd, 0));
    }
    get_next_line(fd, 1);
    close(fd);
    return(list_to_obj(scene));
}

void ft_free_obj(t_obj *obj)
{
    (void)obj;
}

void ft_free_light(t_light *light)
{
    //free(light->point);
    free(light);
}

void ft_free_cam(t_cam *cam)
{
    //free(cam->normal);
    //free(cam->view_point);
    free(cam);
}

void ft_free_amb(t_amb *amb)
{
    //free(&amb->color);
    free(amb);
}

void ft_free_scene(t_scene *scene)
{
    int i;
    t_obj_list *head;

    i = 0;
    head = scene->temp;
    ft_free_amb(scene->amb);
    ft_free_cam(scene->cam);
    ft_free_light(scene->light);
    // while (head != NULL)
    // {
    //     i++;
    //     free(head->obj);
    //     head = head->next;
    // }
    // while(--i >= 0)
    //     ft_free_obj(&scene->obj[i]);
    // free(scene->temp);
    // free(scene);
}

int main(int argc, char **argv)
{
    t_scene scene;
    //validacao da extensao .rt esta errada. se o mapa tiver um . no nome da erro 
    if (argc != 2) //|| ft_strcmp(argv[1] + ft_strclen(argv[1], '.'), ".rt"))
	{
		ft_printf("minirt: INSERT <file.rt>\n");
		return (1);
	}
    init_scene(&scene);
    map_validate(argv[1], &scene);
    printf("CAM FOV : %f\n", scene.cam->fov_x);
    ft_free_scene(&scene);
    return(0);
}
