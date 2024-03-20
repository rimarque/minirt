/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:07:10 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/26 22:07:33 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ft_initobj(t_obj *obj)
{
	obj->color = get_color(0, 0, 0);
	obj->r = 0;
	obj->r_sqr = 0;
	obj->h = 0;
	obj->type = 0;
	set_coord(&obj->point, 0, 0, 0);
	set_coord(&obj->vector, 0, 0, 0);
	set_coord(&obj->vec_inver, 0, 0, 0);
	set_coord(&obj->base1_c, 0, 0, 0);
	set_coord(&obj->base2_c, 0, 0, 0);
}

int	list_to_obj(t_scene *scene)
{
	t_obj_list	*head;
	int			i;
	int			erro;

	scene->n_obj = ft_stack_length(scene->temp);
	if (scene->n_obj == 0)
		return (0);
	scene->obj = (t_obj *)malloc(sizeof(t_obj) * scene->n_obj);
	head = scene->temp;
	i = -1;
	while (head != NULL)
	{
		erro = validate_obj(head->obj, &scene->obj[++i]);
		if (erro == 0)
		{
			ft_putstr_fd("minirt: Invalid Map Lista\n", 2);
			return (0);
		}
		head = head->next;
	}
	return (1);
}

int	open_map(char *str)
{
	int	fd;

	fd = -1;
	if (!access(str, F_OK))
		fd = open(str, O_RDONLY);
	else
		ft_putstr_fd("Invalid Map Open\n", 2);
	return (fd);
}

int	map_validate(char *file, t_scene *scene)
{
	int		fd;
	char	*line;

	fd = open_map(file);
	if (fd == -1)
		return (0);
	line = ft_strtrimall(get_next_line(fd, 0));
	while (line)
	{
		if (line[0] != '#' && !validate_line(line, scene))
		{
			free(line);
			ft_putstr_fd("Invalid Map line\n", 2);
			get_next_line(fd, 1);
			close(fd);
			return (0);
		}
		else
			free(line);
		line = ft_strtrimall(get_next_line(fd, 0));
	}
	get_next_line(fd, 1);
	close(fd);
	return (list_to_obj(scene) & final_check(scene));
}
