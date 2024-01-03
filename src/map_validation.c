/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:07:10 by bde-sous          #+#    #+#             */
/*   Updated: 2024/01/03 22:17:42 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_validation.h"


int validate_A(char **line)
{
    if (ft_arrlen(line) == 3)
    {
        printf("%s\n", line[0]);
        printf("%f\n", ft_atof(line[1]));
        printf("%s\n", line[2]);
        return(1);
    }
    ft_free_array(&line);
    return(0);
}

int validate_C(char **line)
{
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

int validate_L(char **line)
{
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

int validate_sp(char **line)
{
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
int validate_cy(char **line)
{
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
int validate_pl(char **line)
{
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

int validate_line(char *line)
{
    char **words;
    if (!line)
        return(0);
    words = ft_split(line, ' ');
    if (ft_strlen(words[0]) == 1 && !ft_strcmp(words[0], "A"))
        return(validate_A(words));
    if (ft_strlen(words[0]) == 1 && !ft_strcmp(words[0], "C"))
        return(validate_C(words));
    if (ft_strlen(words[0]) == 1 && !ft_strcmp(words[0], "L"))
        return(validate_L(words));
    if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "sp"))
        return(validate_sp(words));
    if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "pl"))
        return(validate_pl(words));
    if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "cy"))
        return(validate_cy(words));
    if (words[0][0] == 10)
        return(1);
    ft_free_array(&words);
    return(0);
}



int map_validate(char *file)
{
    int fd; 
    char *line;
    
    fd = 0;
    fd = open(file, O_RDONLY);
    line = ft_strtrimall(get_next_line(fd, 0));
    while (line)
    {
        if(!validate_line(line))
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
    if (argc != 2 || ft_strcmp(argv[1] + ft_strclen(argv[1], '.'), ".rt"))
	{
		ft_printf("minirt: INSERT <file.rt>\n");
		return (1);
	}
    map_validate(argv[1]);
    return(0);
}