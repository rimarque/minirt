/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:54:37 by rita              #+#    #+#             */
/*   Updated: 2024/02/13 19:50:03 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void    compute_auxvariables(t_obj *obj)
{
    obj->vec_inver = vec3_scale(obj->vector, -1);
    obj->base1_c = vec3_add(obj->point, 
        vec3_scale(obj->vector, obj->h/2));
    obj->base2_c = vec3_add(obj->point, 
        vec3_scale(obj->vec_inver, obj->h/2));
}

t_rgb   get_color(uint8_t r, uint8_t g, uint8_t b)
{
	t_rgb	color;

    color.r = r;
    color.g = g;
    color.b = b;
	return (color);
}