/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:54:37 by rita              #+#    #+#             */
/*   Updated: 2024/02/26 22:06:12 by rita             ###   ########.fr       */
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