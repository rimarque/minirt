/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:06:32 by rita              #+#    #+#             */
/*   Updated: 2024/02/26 18:27:07 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	rotate_obj_x(t_obj *obj, float ang)
{
	obj->vector = vec3_mltmatrix(get_rotmatrix_x(ang), obj->vector);
}

void	rotate_obj_y(t_obj *obj, float ang)
{
	obj->vector = vec3_mltmatrix(get_rotmatrix_y(ang), obj->vector);
}

void	rotate_obj_z(t_obj *obj, float ang)
{
	obj->vector = vec3_mltmatrix(get_rotmatrix_z(ang), obj->vector);
}

void    rotate_obj(t_obj *obj, int button)
{
    if(button == UP)
		rotate_obj_x(obj, ANG_ROT);
	if(button == DOWN)
		rotate_obj_x(obj, -ANG_ROT);
	if(button == RIGHT)
		rotate_obj_y(obj, -ANG_ROT);
	if(button == LEFT)
		rotate_obj_y(obj, ANG_ROT);
	if(button == SHIFT_RIGHT)
		rotate_obj_z(obj, -ANG_ROT);
	if(button == CTRL_RIGHT)
		rotate_obj_z(obj, ANG_ROT);
	if(obj->type == CY)
		compute_cy_aux_var(obj);
}