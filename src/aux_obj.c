/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:54:37 by rita              #+#    #+#             */
/*   Updated: 2024/02/24 15:59:31 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_rgb   get_color(uint8_t r, uint8_t g, uint8_t b)
{
	t_rgb	color;

    color.r = r;
    color.g = g;
    color.b = b;
	return (color);
}

void    compute_auxvar_cy(t_obj *obj)
{
    obj->vec_inver = vec3_scale(obj->vector, -1);
    obj->base1_c = vec3_add(obj->point, 
        vec3_scale(obj->vector, obj->h/2));
    obj->base2_c = vec3_add(obj->point, 
        vec3_scale(obj->vec_inver, obj->h/2));
}

//o = origem do raio
/* void    compute_auxvar_qf(t_obj *obj, t_vec3 o)
{
    if(obj->type == CY)
    {
        obj->co = vec3_sub(o, obj->base1_c);
        obj->dot_cov = vec3_dot(obj->co, obj->vec_inver);
        obj->qf_c = vec3_dot(obj->co, obj->co) - (obj->dot_cov * obj->dot_cov) - obj->r_sqr;
    }
    if(obj->type == SP)
    {
        obj->co = vec3_sub(o, obj->point);
        obj->qf_c = vec3_dot(obj->co, obj->co) - obj->r_sqr;
    }
} */