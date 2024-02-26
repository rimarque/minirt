/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:54:37 by rita              #+#    #+#             */
/*   Updated: 2024/02/26 18:56:27 by rita             ###   ########.fr       */
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

void    compute_cy_aux_var(t_obj *cy)
{
    cy->vec_inver = vec3_scale(cy->vector, -1);
    cy->base1_c = vec3_add(cy->point, 
        vec3_scale(cy->vector, cy->h/2));
    cy->base2_c = vec3_add(cy->point, 
        vec3_scale(cy->vec_inver, cy->h/2));
}

//o = origem do raio
void    compute_qf_aux_var_sp(t_obj *sp, t_vec3 o)
{
    sp->co = vec3_sub(o, sp->point);
    sp->qf_c = vec3_dot(sp->co, sp->co) - sp->r_sqr;
}

void    compute_qf_aux_var_cy(t_obj *cy, t_vec3 o)
{
        cy->co = vec3_sub(o, cy->base1_c);
        cy->dot_cov = vec3_dot(cy->co, cy->vec_inver);
        cy->qf_c = vec3_dot(cy->co, cy->co) - (cy->dot_cov * cy->dot_cov) - cy->r_sqr;
}

void    compute_ray_origin_dependet_var(t_obj *obj, t_vec3 ray_o, int n_obj)
{
    int i;

    i = 0;
    while(i < n_obj)
    {
        if(obj[i].type == SP)
            compute_qf_aux_var_sp(&obj[i], ray_o);
        if(obj[i].type == CY)
            compute_qf_aux_var_cy(&obj[i], ray_o);
        i++;
    }
}