/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:00:31 by rita              #+#    #+#             */
/*   Updated: 2024/02/13 21:02:28 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	translate_point_y(t_vec3 *point, float scale)
{
	t_vec3	dir;

	set_coord(&dir, 0, 1, 0);
	*point = vec3_add(*point, vec3_scale(dir, scale));
}

void	translate_point_x(t_vec3 *point, float scale)
{
	t_vec3	dir;

	set_coord(&dir, 1, 0, 0);
	*point = vec3_add(*point, vec3_scale(dir, scale));
}

void	translate_point_z(t_vec3 *point, float scale)
{
	t_vec3	dir;

	set_coord(&dir, 0, 0, 1);
	*point = vec3_add(*point, vec3_scale(dir, scale));
}

void	translate_point(t_vec3 *point, int button)
{
	if (button == SHIFT_LEFT)
		translate_point_y(point, SCALE_TRANS);
	if (button == CTRL_LEFT)
		translate_point_y(point, -SCALE_TRANS);
	if (button == D)
		translate_point_x(point, SCALE_TRANS);
	if (button == A)
		translate_point_x(point, -SCALE_TRANS);
	if (button == W)
		translate_point_z(point, -SCALE_TRANS);
	if (button == S)
		translate_point_z(point, SCALE_TRANS);
}
