/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cybase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:41:53 by rita              #+#    #+#             */
/*   Updated: 2024/02/13 19:48:19 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool in_circle(t_vec3 p, t_vec3 c, float r_sqr)
{
	if (vec3_lensqr(vec3_sub(p, c)) <= r_sqr)
		return(true);
	return(false);
}

t_inter inter_onebase(t_ray ray, t_obj cy, t_vec3 c, t_vec3 v)
{
	t_inter	it;
	float	dot_dv;
	
	it.inter = false;
	dot_dv = vec3_dot(vec3_normalized(ray.d), v);
	if(dot_dv == 0)
		return(it);
	it.t = vec3_dot(vec3_sub(c, ray.o), v) / dot_dv;
	if(it.t < 0 && it.t < 0)
		return(it);
	it.point = vec3_add(ray.o, vec3_scale(ray.d, it.t));
	if(!in_circle(it.point, c, cy.r_sqr))
		return(it);
	it.normal = v;
	it.inter = true;
	return(it);
}

t_inter	inter_base(t_ray ray, t_obj cy)
{
	t_inter it1;
	t_inter it2;

	it1 = inter_onebase(ray, cy, cy.base1_c, cy.vector);
	it2 = inter_onebase(ray, cy, cy.base2_c, cy.vec_inver);
	if(it1.inter == true && it2.inter == true)
		it1 = closer_inter(it1, it2);
	else if(it2.inter == true)
		it1 = it2;
	return(it1);
}