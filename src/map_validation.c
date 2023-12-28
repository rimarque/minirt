/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:07:10 by bde-sous          #+#    #+#             */
/*   Updated: 2023/12/28 17:39:31 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_validation.h"\

int validate_line(char *line)
{
    if (!line)
        return(0);
    printf("%s", line);
    return(1);
}

int map_validate(char *file)
{
    int fd; 
    char *line;

    fd = 0;
    fd = open(file, O_RDONLY);
    printf("fd: %d \n", fd);
    line = get_next_line(fd, 0);
    while (line)
    {
        if(!validate_line(line))
        {
            free(line);
            break;
        }
        else
            free(line);
        line = get_next_line(fd, 0);
    }
    get_next_line(fd, 1);
    return(1);
}

int main(int argc, char **argv)
{
    if (argc != 2 || ft_strcmp(argv[1] + ft_strclen(argv[1], '.'), ".rt"))
	{
		ft_printf("minirt: INSERT <file.rt>\n");
		return (1);
	}
    map_validate(argv[1]);
    return(0);
}