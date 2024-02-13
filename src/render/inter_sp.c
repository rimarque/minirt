/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:34:17 by rita              #+#    #+#             */
/*   Updated: 2024/02/13 20:20:25 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	in_sp_surface(t_ray ray, t_obj sp, t_auxeq *aux)
{
	t_vec3	co;
	float	a;
	float	b;
	float	c;

	co = vec3_sub(ray.o, sp.point);
	a = vec3_dot(ray.d, ray.d);
	b = 2 * vec3_dot(ray.d, co);
	c = vec3_dot(co, co) - sp.r_sqr;
	if(!aply_quadratic_form(a, b, c, aux))
		return (false);
	return (true);
}

t_inter	inter_sp(t_ray ray, t_obj sp, t_inter prev_it)
{
	t_inter	it;
	t_auxeq aux;
	
	if(!in_sp_surface(ray, sp, &aux) || (aux.t1 < 0 && aux.t2 < 0))
		return(it.inter = false, it);
	it.inter = true;
	it.t = closer_t(aux.in_sqrt, aux.t1, aux.t2);
	it.point = vec3_add(ray.o, vec3_scale(ray.d, it.t));
	it.normal = vec3_normalized(vec3_sub(it.point, sp.point));
	if(prev_it.inter && prev_it.t < it.t)
		return(it.inter = false, it);
	return(it);
}