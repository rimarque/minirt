/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:07:10 by bde-sous          #+#    #+#             */
/*   Updated: 2024/01/31 13:22:58 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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

int	ft_ischar(const char *str, uint8_t *val)
{
	int	i;
    int res;

	i = 0;
	if (ft_strlen(str) == 0 || ft_strlen(str) > 3)
		return (0);
	while (str[i] >= '0' && str[i] <= '5')
		i++;
	if (str[i] != '\0')
		return (0);
    res = ft_atoi(str);
	if (res > 255 || res < 0)
		return (0);
    *val = res;
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
    if (normalized == 1 && (!float_in_range(*val, -1, 1)))
        return (0);
    if (normalized == 2 && (*val <= 0))
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
        if (ft_ischar(raw[i], &irgb[i]))
            i++;
        else
            return(0 & ft_freedoublepointer(raw));
    }
    if(ft_arrlen(raw) != 3)
        return(0 & ft_freedoublepointer(raw));
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
    raw = ft_split(str,',');
    while(ft_arrlen(raw) == 3 && i < 3)
    {
        if (ft_isfloat(raw[i], &ivec[i], normalized))
            i++;
        else
            return(0 & ft_freedoublepointer(raw));
    }
    if (ft_arrlen(raw) != 3)
        return(ft_freedoublepointer(raw) & 0);
    ft_freedoublepointer(raw);
    vec->x=ivec[0];
    vec->y=ivec[1];
    vec->z=ivec[2];
    return(1);
}

int validate_A(char **line, t_scene *scene)
{
    if (ft_arrlen(line) == 3 && scene->amb == NULL)
    {
        scene->amb = malloc(sizeof(t_amb));
        if (scene->amb == NULL)
            return (0);
        scene->amb->ratio = ft_atof(line[1]);
        if (!parse_color(line[2], &scene->amb->c))
            return(0);
        if (!(float_in_range(scene->amb->ratio, 0, 1)) || !ft_isdigit(line[1][0]))
            return(0);
        return(1);
    }
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
        scene->cam->aspect = (float)WIN_H/WIN_W;
        scene->cam->axis = get_camaxis(scene->cam->normal, scene->cam->view_point);
        return(1);
    }
    return(0);
}

int validate_L(char **line, t_scene *scene)
{
    if (ft_arrlen(line) == 3 && scene->light == NULL)
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
    return(0);
}

int validate_sp(char **line, t_obj *obj)
{
    if (ft_arrlen(line) == 4)
    {
        if (!parse_vec3(line[1], &obj->point, 0))
            return(0);
        if (!ft_isfloat(line[2], &obj->r, 2))
            return(0);
        if (!parse_color(line[3], &obj->c))
            return(0);
        obj->type = SP;
        obj->r /= 2;
        obj->r_sq = obj->r*obj->r;
        return(1);
    }
    return(0);
}

int validate_cy(char **line, t_obj *obj)
{
    if (ft_arrlen(line) == 6)
    {
        if (!parse_vec3(line[1], &obj->point, 0))
            return(0);
        if (!parse_vec3(line[2], &obj->vector, 1))
            return(0);
        if (!ft_isfloat(line[3], &obj->r, 2))
            return(0);
        if (!ft_isfloat(line[4], &obj->h, 2))
            return(0);
        if (!parse_color(line[5], &obj->c))
            return(0);
        obj->type = CY;
        obj->r /= 2;
        obj->r_sq = obj->r*obj->r;
        return(1);
    }
    return(0);
}

int validate_pl(char **line, t_obj *obj)
{
    if (ft_arrlen(line) == 4)
    {
        if (!parse_vec3(line[1], &obj->point, 0))
            return(0);
        if (!parse_vec3(line[2], &obj->vector, 1))
            return(0);
        if (!parse_color(line[3], &obj->c))
            return(0);
        obj->type = PL;
        return(1);
    }
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

void ft_initobj(t_obj *obj)
{
    obj->c.b = 0;
    obj->c.r = 0;
    obj->c.g = 0;
    obj->r = 0;
    obj->h = 0;
    obj->type = 0;
    obj->vector.x = 0;
    obj->vector.y = 0;
    obj->vector.z = 0;
    obj->point.x = 0;
    obj->point.y = 0;
    obj->point.z = 0;
}

int validate_obj(char *line, t_obj *obj)
{
    char **words;

    if (!line)
        return(0);
    words = ft_split(line, ' ');
    ft_initobj(obj);
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

    scene->n_obj = ft_stack_length(scene->temp);
    if(scene->n_obj == 0)
        return(0);
    scene->obj = (t_obj *)malloc(sizeof(t_obj) * scene->n_obj);
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

int ft_put_err()
{
    ft_putstr_fd("Invalid Map\n",2);
    return(0);
}

int final_check(t_scene *scene)
{
    if(scene->amb == NULL)
        return(ft_put_err() & 0);
    if(scene->cam == NULL)
        return(ft_put_err() & 0);
    if(scene->light == NULL)
        return(ft_put_err() & 0);
    if(scene->obj == NULL)
        return(ft_put_err() & 0);
    if(scene->temp == NULL)
        return(ft_put_err() & 0);
    return(1);
}

int open_map(char *str)
{
    int fd;

    fd = -1;
    if (!access(str, F_OK))
        fd = open(str, O_RDONLY);
    else
        ft_putstr_fd("Invalid Map\n",2);
    return(fd);
}

int map_validate(char *file, t_scene *scene)
{
    int     fd; 
    char    *line;

    fd = open_map(file);
    if (fd == -1)
		return (0);
    line = ft_strtrimall(get_next_line(fd, 0));
    while (line)
    {
        if(!validate_line(line, scene))
        {
            free(line);
            ft_putstr_fd("Invalid Map\n",2);
            get_next_line(fd, 1);
            close(fd);
            return(0);
        }
        else
            free(line);
        line = ft_strtrimall(get_next_line(fd, 0));
    }
    get_next_line(fd, 1);
    close(fd);
    return(list_to_obj(scene) & final_check(scene));
}

int	freestack(t_obj_list *stack)
{
	t_obj_list	*aux;
    int i;

    i = 0;
	while (stack != NULL)
	{
		aux = stack;
		stack = stack->next;
        free(aux->obj);
		free(aux);
        i++;
	}
    return(i);
}

void ft_free_objarray(t_obj *obj, int len)
{
    int i;

    i = 0;
    if (obj == NULL)
        return;
    while (i < len)
        free(&obj[i]);
    free(obj);
}

void ft_free_scene(t_scene *scene)
{
    if (scene->amb != NULL)
        free(scene->amb);
    if (scene->cam != NULL)
        free(scene->cam);
    if (scene->light != NULL)
        free(scene->light);
    if (scene->temp != NULL)
        freestack(scene->temp);
    if (scene->obj != NULL)
        free(scene->obj);
}

void ft_print_vec(t_vec3 *vec)
{
    printf("vec:        x %f\n", vec->x);
    printf("            y %f\n", vec->y);
    printf("            z %f\n", vec->z);
}

void ft_print_color(t_rgb *rgb)
{
    printf("RGB:        r %d\n", rgb->r);
    printf("            g %d\n", rgb->g);
    printf("            b %d\n", rgb->b);
}

void ft_print_amb(t_amb *amb)
{
    printf("---AMBIENTE---\n\n");
    printf("ratio:      %f\n", amb->ratio);
    ft_print_color(&amb->c);  
    printf("\n\n");
}

void ft_print_cam(t_cam *cam)
{
    printf("---CAMARA---\n\n");
    printf("view_point\n");
    ft_print_vec(&cam->view_point);
    printf("normalized\n");
    ft_print_vec(&cam->normal);
    printf("FOV X:      %f\n", cam->fov_x);
    printf("\n\n");
}

void ft_print_light(t_light *light)
{
    printf("---LIGHT---\n\n");
    printf("point\n");
    ft_print_vec(&light->point);
    printf("Ratio:      %f\n", light->ratio);
    printf("\n\n");
}

void ft_print_obj(t_obj *obj, int num)
{
    int i;
    char   *tipos[3] = {"PL", "SP", "CY"};

    printf("---OBJECTS---\n\n");
    i = -1;
    while (i++ < num -1)
    {
        printf("Obj %d %s\n", i, tipos[obj[i].type]);
        ft_print_color(&obj[i].c);
        printf("point\n");
        ft_print_vec(&obj[i].point);
        printf("normalized\n");
        ft_print_vec(&obj[i].vector);
        printf("R:          %f\n", obj[i].r);
        printf("R SQ:          %f\n", obj[i].r_sq);
        printf("H:          %f\n", obj[i].h);
        printf("\n");
    }
    printf("\n\n");
}

void ft_print_scene(t_scene *scene)
{
    ft_print_amb(scene->amb);
    ft_print_cam(scene->cam);
    ft_print_light(scene->light);
    ft_print_obj(scene->obj, scene->n_obj);
}



// int main(int argc, char **argv)
// {
//     t_scene scene;
    
//     //validacao da extensao .rt esta errada. se o mapa tiver um . no nome da erro 
//     if (argc != 2) //|| ft_strcmp(argv[1] + ft_strclen(argv[1], '.'), ".rt"))
// 	{
// 		ft_printf("minirt: INSERT <file.rt>\n");
// 		return (1);
// 	}
//     init_scene(&scene);
//     if(map_validate(argv[1], &scene) == 1)
//         ft_print_scene(&scene);
//     ft_free_scene(&scene);
//     return(0);
// }
