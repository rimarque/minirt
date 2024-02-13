/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:00:31 by rita              #+#    #+#             */
/*   Updated: 2024/02/13 12:31:46 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	translate_obj_y(t_obj *obj, int i, float scale)
{
	t_vec3	dir;

	set_coord(&dir, 0, 1, 0);
	obj[i].point = vec3_add(obj[i].point, 
	vec3_scale(dir, scale));
	if(obj[i].type == CY)
		compute_auxvariables(&obj[i]);
}

void	translate_obj_x(t_obj *obj, int i, float scale)
{
	t_vec3	dir;

	set_coord(&dir, 1, 0, 0);
	obj[i].point = vec3_add(obj[i].point, 
	vec3_scale(dir, scale));
	if(obj[i].type == CY)
		compute_auxvariables(&obj[i]);
}

void	translate_obj_z(t_obj *obj, int i, float scale)
{
	t_vec3	dir;

	set_coord(&dir, 0, 0, 1);
	obj[i].point = vec3_add(obj[i].point, 
	vec3_scale(dir, scale));
	if(obj[i].type == CY)
		compute_auxvariables(&obj[i]);
}

void	translate_obj(t_obj *obj, int  i, int button)
{
	if(button == SHIFT_LEFT)
		translate_obj_y(obj, i, SCALE_TRANS);
	if(button == CTRL_LEFT)
		translate_obj_y(obj, i, -SCALE_TRANS);
	if(button == D)
		translate_obj_x(obj, i, SCALE_TRANS);
	if(button == A)
		translate_obj_x(obj, i, -SCALE_TRANS);
	if(button == W)
		translate_obj_z(obj, i, -SCALE_TRANS);
	if(button == S)
		translate_obj_z(obj, i, SCALE_TRANS);
}