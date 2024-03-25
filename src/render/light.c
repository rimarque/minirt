/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:12:17 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/27 10:49:58 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	get_min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

bool	shadow(t_scene scene, t_inter it, t_vec3 l, float len_l)
{
	t_ray	light_ray;

	light_ray.o = it.point;
	light_ray.d = l;
	if (lig_ray_int_obj(light_ray, scene, it.i, len_l))
		return (true);
	return (false);
}

float	compute_light(t_scene scene, t_inter it)
{
	float	i;
	float	dot;
	t_vec3	l;
	float	len_l;
	float	distance_factor;

	i = scene.amb->ratio;
	l = vec3_sub(scene.light->point, it.point);
	len_l = vec3_lenght(l);
	l = vec3_normalized(l);
	dot = vec3_dot(it.normal, l);
	if (dot > 0 && !shadow(scene, it, l, len_l))
	{
		distance_factor = get_min(1.0, LIGHT_RANGE / len_l);
		i += (scene.light->ratio * dot) * distance_factor;
	}
	return (get_min(1.0, i));
}
