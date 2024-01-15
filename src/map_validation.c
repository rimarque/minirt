/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:07:10 by bde-sous          #+#    #+#             */
/*   Updated: 2024/01/07 18:01:11 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_validation.h"
#include <stdlib.h>


/*bool check_ambient_ratio(float ratio)
{
    return (ratio >=  0 && ratio <= 1);
} */

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
    rgb = malloc(sizeof(t_rgb));
    if(rgb == NULL)
        return(0);
    rgb->r=irgb[0];
    rgb->r=irgb[1];
    rgb->r=irgb[2];
    return(1);
}

int float_in_range(float value, float min, float max)
{
    return(value >= min && value <= max);
}

int validate_A(char **line, t_scene *scene)
{
    if (ft_arrlen(line) == 3 && scene->amb == NULL)
    {
        scene->amb = malloc(sizeof(t_amb));
        if (scene->amb == NULL)
            return 0;
        scene->amb->ratio = ft_atof(line[1]);
        if (!parse_color(line[2], scene->amb->color))
            return(0);
        if (!float_in_range(scene->amb->ratio, 0, 1) || !ft_isdigit(line[1][0]))
            return(0);
        return(1);
    }
    ft_free_array(&line);
    return(0);
}

int validate_C(char **line, t_scene *scene)
{
    (void)scene;
    if (ft_arrlen(line) == 4 && scene->cam == NULL)
    {
        printf("%s\n", line[0]);
        printf("%s\n", line[1]);
        printf("%s\n", line[2]);
        printf("%s\n", line[3]);
        return(1);
    }
    ft_free_array(&line);
    return(0);
}

int validate_L(char **line, t_scene *scene)
{
    (void)scene;
    if (ft_arrlen(line) == 4 && scene->light == NULL)
    {
        printf("%s\n", line[0]);
        printf("%s\n", line[1]);
        printf("%s\n", line[2]);
        printf("%s\n", line[3]);
        return(1);
    }
    ft_free_array(&line);
    return(0);
}

int validate_sp(char **line, t_scene *scene)
{
    (void)scene;
    if (ft_arrlen(line) == 4)
    {
        printf("%s\n", line[0]);
        printf("%s\n", line[1]);
        printf("%s\n", line[2]);
        printf("%s\n", line[3]);
        return(1);
    }
    ft_free_array(&line);
    return(0);
}
int validate_cy(char **line, t_scene *scene)
{
    (void)scene;
    if (ft_arrlen(line) == 6)
    {
        printf("%s\n", line[0]);
        printf("%s\n", line[1]);
        printf("%s\n", line[2]);
        printf("%s\n", line[3]);
        printf("%s\n", line[4]);
        printf("%s\n", line[5]);
        return(1);
    }
    ft_free_array(&line);
    return(0);
}
int validate_pl(char **line, t_scene *scene)
{
    (void)scene;
    if (ft_arrlen(line) == 4)
    {
        printf("%s\n", line[0]);
        printf("%s\n", line[1]);
        printf("%s\n", line[2]);
        printf("%s\n", line[3]);
        return(1);
    }
    ft_free_array(&line);
    return(0);
}

int validate_line(char *line, t_scene *scene)
{
    char **words;
    if (!line)
        return(0);
    words = ft_split(line, ' ');
    if (ft_strlen(words[0]) == 1 && !ft_strcmp(words[0], "A"))
        return(validate_A(words, scene));
    if (ft_strlen(words[0]) == 1 && !ft_strcmp(words[0], "C"))
        return(validate_C(words, scene));
    if (ft_strlen(words[0]) == 1 && !ft_strcmp(words[0], "L"))
        return(validate_L(words, scene));
    if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "sp"))
        return(validate_sp(words, scene));
    if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "pl"))
        return(validate_pl(words, scene));
    if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "cy"))
        return(validate_cy(words, scene));
    if (words[0][0] == 10)
        return(1);
    ft_free_array(&words);
    return(0);
}

void init_scene(t_scene *scene)
{
    scene->amb = NULL;
    scene->cam = NULL;
    scene->light = NULL;
    scene->obj = NULL;
}

int map_validate(char *file)
{
    int     fd; 
    char    *line;
    t_scene scene;
    
    fd = 0;
    init_scene(&scene);
    fd = open(file, O_RDONLY);
    if (fd == -1)
		return (127);
    line = ft_strtrimall(get_next_line(fd, 0));
    while (line)
    {
        if(!validate_line(line, &scene))
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
    return(1);
}

int main(int argc, char **argv)
{
    //validacao da extensao .rt esta errada. se o mapa tiver um . no nome da erro 
    if (argc != 2) //|| ft_strcmp(argv[1] + ft_strclen(argv[1], '.'), ".rt"))
	{
		ft_printf("minirt: INSERT <file.rt>\n");
		return (1);
	}
    return(map_validate(argv[1]));
}
