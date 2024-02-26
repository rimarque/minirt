/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cysurface.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:43:23 by rita              #+#    #+#             */
/*   Updated: 2024/02/26 22:05:10 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	in_cy_surface(t_ray ray, t_obj cy, t_auxeq *aux)
{
	t_vec3	co;
	float	a;
	float	b;
	float	c;

	co = vec3_sub(ray.o, cy.base1_c);
	aux->dot_dv = vec3_dot(ray.d, cy.vec_inver);
	aux->dot_cov = vec3_dot(co, cy.vec_inver);
	a = vec3_dot(ray.d, ray.d) - aux->dot_dv * aux->dot_dv;
	b = 2 * (vec3_dot(ray.d, co) - aux->dot_dv * aux->dot_cov);
	c = vec3_dot(co, co) - aux->dot_cov * aux->dot_cov - cy.r_sqr;
	if(!aply_quadratic_form(a, b, c, aux))
		return (false);
	return (true);
}

t_inter	get_inter_tm(t_vec3 d, t_obj cy, float dot_cov, float t)
{
	t_inter it;

	it.inter = false;
	if (t < 0)
		return(it);
	it.t = t;
	it.m = vec3_dot(d, vec3_scale(cy.vec_inver, t)) + dot_cov;
	if (it.m < 0 || it.m > cy.h)
		return(it);
	it.inter = true;
	return(it);
}
t_inter	get_inter(t_vec3 d, t_obj cy, t_auxeq	aux)
{
	t_inter	it1;
	t_inter it2;
	
	it1 = get_inter_tm(d, cy, aux.dot_cov, aux.t1);
	it2 = get_inter_tm(d, cy, aux.dot_cov, aux.t2);
	if(it1.inter == true && it2.inter == true)
		it1 = closer_inter(it1, it2);
	else if(it2.inter == true)
		it1 = it2;
	return(it1);
}

t_inter	inter_surface(t_ray ray, t_obj cy)
{
	t_inter it;
	t_auxeq	aux;
	
	it.inter = false;
	if(!in_cy_surface(ray, cy, &aux) || (aux.t1 < 0 && aux.t2 < 0))
		return(it);
	if(aux.in_sqrt == 0)
		it = get_inter_tm(ray.d, cy, aux.dot_cov, aux.t1);
	else
		it = get_inter(ray.d, cy, aux);
	if(it.inter == false)
			return(it);
	it.point = vec3_add(ray.o, vec3_scale(ray.d, it.t));
	it.normal = vec3_normalized(vec3_sub(it.point, vec3_add(cy.base1_c, 
	vec3_scale(cy.vec_inver, it.m)))); //*p - (c + v*m);
	return(it);
}