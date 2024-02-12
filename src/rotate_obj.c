/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:06:32 by rita              #+#    #+#             */
/*   Updated: 2024/02/12 21:59:05 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	rotate_obj_x(t_obj *obj, int i, float ang)
{
	obj[i].vector = vec3_mltmatrix(get_rotmatrix_x(ang), obj[i].vector);
	obj[i].vec_inver = vec3_scale(obj->vector, -1);
	obj->base1_c = vec3_add(obj->point, 
        vec3_scale(obj->vector, obj->h/2));
    obj->base2_c = vec3_add(obj->point, 
        vec3_scale(obj->vec_inver, obj->h/2));
}

void	rotate_obj_y(t_obj *obj, int i, float ang)
{
	obj[i].vector = vec3_mltmatrix(get_rotmatrix_y(ang), obj[i].vector);
	obj[i].vec_inver = vec3_scale(obj->vector, -1);
	obj->base1_c = vec3_add(obj->point, 
        vec3_scale(obj->vector, obj->h/2));
    obj->base2_c = vec3_add(obj->point, 
        vec3_scale(obj->vec_inver, obj->h/2));
}

void	rotate_obj_z(t_obj *obj, int i, float ang)
{
	obj[i].vector = vec3_mltmatrix(get_rotmatrix_z(ang), obj[i].vector);
	obj[i].vec_inver = vec3_scale(obj->vector, -1);
	obj->base1_c = vec3_add(obj->point, 
        vec3_scale(obj->vector, obj->h/2));
    obj->base2_c = vec3_add(obj->point, 
        vec3_scale(obj->vec_inver, obj->h/2));
}

void    rotate_obj(t_obj *obj, int  i, int button)
{
    if(button == UP)
		rotate_obj_x(obj, i, ANG_ROT);
	if(button == DOWN)
		rotate_obj_x(obj, i, -ANG_ROT);
	if(button == RIGHT)
		rotate_obj_y(obj, i, -ANG_ROT);
	if(button == LEFT)
		rotate_obj_y(obj, i, ANG_ROT);
	if(button == SHIFT_RIGHT)
		rotate_obj_z(obj, i, -ANG_ROT);
	if(button == CTRL_RIGHT)
		rotate_obj_z(obj, i, ANG_ROT);
}