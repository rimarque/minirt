/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:36:21 by rita              #+#    #+#             */
/*   Updated: 2024/02/03 20:04:11 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

bool	in_cy(t_ray ray, t_obj cy, t_auxeq *aux)
{
	t_vec3	co;
	float	a;
	float	b;
	float	c;

	co = vec3_sub(ray.o, cy.point);
	aux->dot_dv = vec3_dot(ray.d, cy.vector);
	aux->dot_cov = vec3_dot(co, cy.vector);
	a = vec3_dot(ray.d, ray.d) - aux->dot_dv * aux->dot_dv;
	b = 2 * (vec3_dot(ray.d, co) - aux->dot_dv * aux->dot_cov);
	c = vec3_dot(co, co) - aux->dot_cov * aux->dot_cov - cy.r_sq;
	aux->in_sqrt = b * b - 4 * a * c;
	if (aux->in_sqrt < 0)
		return(false);
	aux->t1 = (-b + sqrtf(aux->in_sqrt)) / 2 * a;
	aux->t2 = (-b - sqrtf(aux->in_sqrt)) / 2 * a;
	return(true);
}

t_inter	closer_inter(t_inter it1, t_inter it2)
{
	if(it1.t > 0 && it2.t > 0)
	{
		if(it1.t < it2.t)
			return(it1);
		else
			return(it2);
	}
	else if(it1.t > 0)
		return(it1);
	return(it2);
}

t_inter	inter_caps(t_ray ray, t_obj cy)
{
	t_obj	pl;
	t_auxeq	aux;
	t_inter it;

	aux.dot_dv = vec3_dot(vec3_normalized(ray.d), cy.vector);
	if(aux.dot_dv == 0)
		it.inter = false;
	aux.t1 = vec3_dot(vec3_sub(cy.cap_c, ray.o), pl.vector) / aux.dot_dv;
	aux.t2 = vec3_dot(vec3_sub(cy.cap2_c, ray.o), pl.vector) / aux.dot_dv;
	if(aux.t1 < 0 && aux.t2 < 0)
		return(it.inter = false, it);
	it.t = closer_t(aux.t1, aux.t2);
	it.point = vec3_add(ray.o, vec3_scale(ray.d, it.t));
	it.inter = true;
	if(it.t == aux.t1)
		it.normal = cy.vector;
	else
		it.normal = cy.vec_inver;
	return(it);
}

t_inter inter_cy(t_ray ray, t_obj cy, t_inter prev_it)
{
	t_inter it;
	t_inter	it_caps;
	t_auxeq aux;

    if(!in_cy(ray, cy, &aux) || (aux.t1 < 0 && aux.t2 < 0))
		return(it.inter = false, it);
	if(aux.in_sqrt == 0)
		it.t = aux.t1;
	else
		it.t = closer_t(aux.t1, aux.t2);
	aux.m = vec3_dot(ray.d, vec3_scale(cy.vec_inver, it.t)) + aux.dot_cov;
	if (aux.m > cy.h || aux.m < 0)
		it.inter = false;
	else
	{
		it.inter = true;
		it.point = vec3_add(ray.o, vec3_scale(ray.d, aux.t1));
		it.normal = vec3_normalized(vec3_sub(it.point, vec3_sub(cy.cap_c, vec3_scale(vec_inver, aux.m))));
	}
	it_caps = inter_caps(ray, cy);
	if(it.inter == true && it_caps.inter == true)
		it = closer_inter(it, it_caps);
	else if(it_caps.inter == true)
		it = it_caps;
	if(prev_it.inter && prev_it.t < it.t)
		return(it.inter = false, it);
	return(it);
}