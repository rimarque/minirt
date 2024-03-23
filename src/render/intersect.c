/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:49:36 by rita              #+#    #+#             */
/*   Updated: 2024/02/27 10:48:45 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_inter	inter_obj(t_ray ray, t_obj obj, int i, t_inter prev_it)
{
	t_inter	it;

	if (obj.type == PL)
	{
		it = inter_pl(ray, obj, prev_it);
		it.i = i;
	}
	if (obj.type == SP)
	{
		it = inter_sp(ray, obj, prev_it);
		it.i = i;
	}
	if (obj.type == CY)
	{
		it = inter_cy(ray, obj, prev_it);
		it.i = i;
	}
	return (it);
}

t_inter	cam_ray_intersect_obj(t_ray ray, t_obj *obj, int n)
{
	int		i;
	t_inter	prev_it;
	t_inter	it;

	ft_memset(&prev_it, 0, sizeof(t_inter));
	prev_it.inter = false;
	i = 0;
	while (i < n)
	{
		it = inter_obj(ray, obj[i], i, prev_it);
		if (it.inter)
			prev_it = it;
		i++;
	}
	return (prev_it);
}

bool	lig_ray_int_obj(t_ray ray, t_scene scene, int avoid, float len_l)
{
	int		i;
	t_inter	prev_it;
	t_inter	it;

	prev_it.inter = false;
	i = 0;
	while (i < scene.n_obj)
	{
		if (i != avoid)
		{
			it = inter_obj(ray, scene.obj[i], i, prev_it);
			if (it.inter && it.t < len_l)
				return (true);
		}
		i++;
	}
	return (false);
}
