/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:34:17 by rita              #+#    #+#             */
/*   Updated: 2024/02/04 13:52:28 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

bool	in_sp(t_ray ray, t_obj sp, t_auxeq *aux)
{
	t_vec3	co;
	float	a;
	float	b;
	float	c;

	co = vec3_sub(ray.o, sp.point); //!X
	a = vec3_dot(ray.d, ray.d);
	b = 2 * vec3_dot(ray.d, co);
	c = vec3_dot(co, co) - sp.r_sq;
	aux->in_sqrt = b * b - 4 * a * c;
	if (aux->in_sqrt < 0)
		return(false);
	aux->t1 = (-b + sqrtf(aux->in_sqrt)) / 2 * a;
	aux->t2 = (-b - sqrtf(aux->in_sqrt)) / 2 * a;
	return(true);
}
float	closer_t(float in_sqrt, float t1, float t2)
{
	if(in_sqrt == 0)
		return(t1);
	if(t1 > 0 && t2 > 0)
	{
		if(t1 < t2)
			return(t1);
		else
			return(t2);
	}
	else if(t1 > 0)
		return(t1);
	return(t2);
}

t_inter	inter_sp(t_ray ray, t_obj sp, t_inter prev_it)
{
	t_inter	it;
	t_auxeq aux;
	
	if(!in_sp(ray, sp, &aux) || (aux.t1 < 0 && aux.t2 < 0))
		return(it.inter = false, it);
	it.inter = true;
	it.t = closer_t(aux.in_sqrt, aux.t1, aux.t2);
	it.point = vec3_add(ray.o, vec3_scale(ray.d, it.t));
	it.normal = vec3_normalized(vec3_sub(it.point, sp.point));
	if(prev_it.inter && prev_it.t < it.t)
		return(it.inter = false, it);
	return(it);
}