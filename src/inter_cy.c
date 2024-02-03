/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:36:21 by rita              #+#    #+#             */
/*   Updated: 2024/02/03 17:08:53 by rita             ###   ########.fr       */
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

t_inter inter_cy(t_ray ray, t_obj cy, t_inter prev_it)
{
	t_inter it;
	t_auxeq aux;
	t_vec3	cap_c;
	
	cap_c = vec3_scale(cy.point, cy.h/2); //!acrescentar no validate.map
	cy.vector = vec3_scale(cy.vector, -1); //!necessario?
    if(!in_cy(ray, cy, &aux) || (aux.t1 < 0 && aux.t2 < 0))
		return(it.inter = false, it);
	it.inter = true;
	if (aux.in_sqrt == 0)
	{
		if(prev_it.inter && prev_it.t < aux.t1)
			return(it.inter = false, it);
		it.t = aux.t1;
		it.point = vec3_add(ray.o, vec3_scale(ray.d, aux.t1));
		aux.m = vec3_dot(ray.d, vec3_scale(cy.vector, it.t)) + aux.dot_cov;
		it.normal = vec3_normalized(vec3_sub(it.point, vec3_sub(cap_c, vec3_scale(cy.vector, aux.m))));
		return(it);
	}
	it.t = closer_t(aux);
	it.point = vec3_add(ray.o, vec3_scale(ray.d, aux.t1));
	aux.m = vec3_dot(ray.d, vec3_scale(cy.vector, it.t)) + aux.dot_cov;
	it.normal = vec3_normalized(vec3_sub(it.point, vec3_sub(cap_c, vec3_scale(cy.vector, aux.m))));
	if (aux.m > cy.h || aux.m < 0)
		return(it.inter = false, it);
	if(prev_it.inter && prev_it.t < it.t)
		return(it.inter = false, it);
	return(it);
}