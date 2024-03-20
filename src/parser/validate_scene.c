/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-18 19:26:13 by bde-sous          #+#    #+#             */
/*   Updated: 2024-03-18 19:26:13 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	validate_a(char **line, t_scene *scene)
{
	if (ft_arrlen(line) == 3 && scene->amb == NULL)
	{
		scene->amb = malloc(sizeof(t_amb));
		if (scene->amb == NULL)
			return (0);
		scene->amb->ratio = ft_atof(line[1]);
		if (!parse_color(line[2], &scene->amb->c))
			return (0);
		if (!(float_in_range(scene->amb->ratio, 0, 1)) || \
			!ft_isdigit(line[1][0]))
			return (0);
		return (1);
	}
	return (0);
}

int	validate_c(char **line, t_scene *scene)
{
	t_vec3	view;

	if (ft_arrlen(line) == 4 && scene->cam == NULL)
	{
		scene->cam = ft_calloc(1, sizeof(t_cam));
		if (scene->cam == NULL)
			return (0);
		if (!parse_vec3(line[1], &scene->cam->view_point, 0))
			return (0);
		if (!parse_vec3(line[2], &view, 1))
			return (0);
		if (!ft_isfloat(line[3], &scene->cam->fov_x, 0))
			return (0);
		if (!(float_in_range(scene->cam->fov_x, 0, 180)) || \
			!ft_isdigit(line[3][0]))
			return (0);
		if (!valid_vector(&view))
			return (0);
		scene->cam->fov_x = scene->cam->fov_x * (PI / 180);
		scene->cam->aspect = (float)WIN_H / WIN_W;
		scene->cam->axis = cam_axis(view);
		return (1);
	}
	return (0);
}

int	validate_l(char **line, t_scene *scene)
{
	if (ft_arrlen(line) == 3 && scene->light == NULL)
	{
		scene->light = ft_calloc(1, sizeof(t_light));
		if (!parse_vec3(line[1], &scene->light->point, 0))
			return (0);
		if (!ft_isfloat(line[2], &scene->light->ratio, 0))
			return (0);
		if (!(float_in_range(scene->light->ratio, 0, 1)) || \
			!ft_isdigit(line[2][0]))
			return (0);
		return (1);
	}
	return (0);
}

int	validate_line(char *line, t_scene *scene)
{
	char	**words;

	if (!line)
		return (0);
	words = ft_split(line, ' ');
	if (ft_strlen(words[0]) == 1 && !ft_strcmp(words[0], "A"))
		return (validate_a(words, scene) & ft_freedoublepointer(words));
	if (ft_strlen(words[0]) == 1 && !ft_strcmp(words[0], "C"))
		return (validate_c(words, scene) & ft_freedoublepointer(words));
	if (ft_strlen(words[0]) == 1 && !ft_strcmp(words[0], "L"))
		return (validate_l(words, scene) & ft_freedoublepointer(words));
	if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "sp"))
		return (add_node(line, &scene->temp) & ft_freedoublepointer(words));
	if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "pl"))
		return (add_node(line, &scene->temp) & ft_freedoublepointer(words));
	if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "cy"))
		return (add_node(line, &scene->temp) & ft_freedoublepointer(words));
	if (words[0][0] == 10)
	{
		ft_freedoublepointer(words);
		return (1);
	}
	ft_freedoublepointer(words);
	return (0);
}
