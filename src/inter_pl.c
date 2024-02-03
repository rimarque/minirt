/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:35:37 by rita              #+#    #+#             */
/*   Updated: 2024/02/03 19:20:20 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_inter	inter_pl(t_ray ray, t_obj pl, t_inter prev_it)
{
	t_inter it;
	float	dot_dv;

	dot_dv = vec3_dot(vec3_normalized(ray.d), pl.vector);
	if(dot_dv == 0)
		return(it.inter = false, it);
	it.t = vec3_dot(vec3_sub(pl.point, ray.o), pl.vector) / dot_dv;
	if(it.t < 0 || (prev_it.inter && prev_it.t < it.t))
		return(it.inter = false, it);
	it.point = vec3_add(ray.o, vec3_scale(ray.d, it.t));
	it.inter = true;
	if(dot_dv > 0)
		it.normal = vec3_scale(pl.vector, -1);
	else
		it.normal = pl.vector;
	return(it);
}