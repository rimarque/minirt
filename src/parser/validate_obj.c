/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-18 19:29:39 by bde-sous          #+#    #+#             */
/*   Updated: 2024-03-18 19:29:39 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	validate_sp(char **line, t_obj *obj)
{
	if (ft_arrlen(line) == 4)
	{
		if (!parse_vec3(line[1], &obj->point, 0))
			return (0);
		if (!ft_isfloat(line[2], &obj->r, 2))
			return (0);
		if (!parse_color(line[3], &obj->color))
			return (0);
		obj->type = SP;
		obj->r = obj->r / 2;
		obj->r_sqr = obj->r * obj->r;
		return (1);
	}
	return (0);
}

int	validate_cy(char **line, t_obj *obj)
{
	if (ft_arrlen(line) == 6)
	{
		if (!parse_vec3(line[1], &obj->point, 0))
			return (0);
		if (!parse_vec3(line[2], &obj->vector, 1))
			return (0);
		if (!ft_isfloat(line[3], &obj->r, 2))
			return (0);
		if (!ft_isfloat(line[4], &obj->h, 2))
			return (0);
		if (!parse_color(line[5], &obj->color))
			return (0);
		if (!valid_vector(&obj->vector))
			return (0);
		obj->type = CY;
		obj->r = obj->r / 2;
		obj->r_sqr = obj->r * obj->r;
		compute_cy_aux_var(obj);
		return (1);
	}
	return (0);
}

int	validate_pl(char **line, t_obj *obj)
{
	if (ft_arrlen(line) == 4)
	{
		if (!parse_vec3(line[1], &obj->point, 0))
			return (0);
		if (!parse_vec3(line[2], &obj->vector, 1))
			return (0);
		if (!parse_color(line[3], &obj->color))
			return (0);
		if (!valid_vector(&obj->vector))
			return (0);
		obj->type = PL;
		return (1);
	}
	return (0);
}

int	validate_obj(char *line, t_obj *obj)
{
	char	**words;

	if (!line)
		return (0);
	words = ft_split(line, ' ');
	ft_initobj(obj);
	if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "sp"))
		return (validate_sp(words, obj) & ft_freedoublepointer(words));
	if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "pl"))
		return (validate_pl(words, obj) & ft_freedoublepointer(words));
	if (ft_strlen(words[0]) == 2 && !ft_strcmp(words[0], "cy"))
		return (validate_cy(words, obj) & ft_freedoublepointer(words));
	if (words[0][0] == 10)
	{
		ft_freedoublepointer(words);
		return (1);
	}
	ft_freedoublepointer(words);
	return (0);
}

int	valid_vector(t_vec3 *vec)
{
	if (vec->x == 0 && vec->y == 0 && vec->z == 0)
		return (0);
	*vec = vec3_normalized(*vec);
	return (1);
}
