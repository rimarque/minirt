/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:36:21 by rita              #+#    #+#             */
/*   Updated: 2024/02/04 22:50:10 by rita             ###   ########.fr       */
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
	aux->dot_dv = vec3_dot(ray.d, cy.vec_inver);
	aux->dot_cov = vec3_dot(co, cy.vec_inver);
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
	
	dot_dv = vec3_dot(vec3_normalized(ray.d), v);
	if(dot_dv == 0)
		return(it.inter = false, it);
	it.t = vec3_dot(vec3_sub(c, ray.o), v) / dot_dv;
	if(it.t < 0 && it.t < 0)
		return(it.inter = false, it);
	it.point = vec3_add(ray.o, vec3_scale(ray.d, it.t));
	if(!in_circle(it.point, c, cy.r_sq))
		return(it.inter = false, it);
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

t_inter	get_inter_tm(t_vec3 d, t_obj cy, float dot_cov, float t)
{
	t_inter it;

	if (t < 0)
		return(it.inter = false, it);
	it.t = t;
	it.m = vec3_dot(d, vec3_scale(cy.vec_inver, t)) + dot_cov;
	if ((it.m < 0 || it.m > cy.h))
		return(it.inter = false, it);
	return(it);
}
t_inter	get_inter_tm2(t_vec3 d, t_obj cy, t_auxeq aux)
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
		
//!normal
//p - c - v*m;
//vec_3_normalized(vec3_sub(vec3_sub(it.point, cy.cap_c), vec3_scale(cy.vec_inver, aux.m)));
t_inter	inter_surface(t_ray ray, t_obj cy)
{
	t_inter it;
	t_auxeq	aux;
	
	if(!in_cy(ray, cy, &aux) || (aux.t1 < 0 && aux.t2 < 0)) //se nao interseta o cilindro infinito
		return(it.inter = false, it);
	if(aux.in_sqrt == 0)
	{
		it = get_inter_tm(ray.d, cy, aux.dot_cov, aux.t1);
		if(it.inter == false)
			return(it);
	}
	else
		it = get_inter_tm2(ray.d, cy, aux);
	it.point = vec3_add(ray.o, vec3_scale(ray.d, it.t));
	it.normal = vec3_normalized(vec3_sub(it.point, vec3_add(cy.base1_c, vec3_scale(cy.vec_inver, it.m)))); //*p - (c + v*m);
	return(it);
}

t_inter inter_cy(t_ray ray, t_obj cy, t_inter prev_it)
{
	t_inter	it;
	t_inter	it_base;
	
	it = inter_surface(ray, cy);
	it_base = inter_base(ray, cy);
	if(it.inter == true && it_base.inter == true)
		it = closer_inter(it, it_base);
	else if(it_base.inter == true)
		it = it_base;
	if(prev_it.inter && prev_it.t < it.t)
		return(it.inter = false, it);
	return(it);
}

/* t_inter	inter_surface_old(t_ray ray, t_obj cy, )
{
	t_auxeq aux;
	
	if(!in_cy(ray, cy, &aux) || (aux.t1 < 0 && aux.t2 < 0)) //se nao interseta o cilindro infinito
		return(it.inter = false, it);
	aux.m1 = vec3_dot(ray.d, vec3_scale(cy.vec_inver, aux.t1)) + aux.dot_cov;
	aux.m2 = vec3_dot(ray.d, vec3_scale(cy.vec_inver, aux.t2)) + aux.dot_cov;
	if (aux.m1 < 0 || aux.m1 > cy.h && aux.m2 < 0 || aux.m2 > cy.h) //se nenhum dos pontos de intersecao esta nos limites da altura do cilindro
		return(it.inter = false, it);
	if (aux.m1 >= 0 && aux.m1 <= cy.h && aux.m2 >= 0 && aux.m2 <= cy.h) //se ambos os pontos de intersecao estao no cilindro
		it.t = closer_t(aux.in_sqrt, aux.t1, aux.t2);               
	else if (aux.m1 >= 0 && aux.m1 <= cy.h) //se apenas o m1 esta no cilindro
		it.t = aux.t1;
	else
		it.t = aux.t2;
	it.point = vec3_add(ray.o, vec3_scale(ray.d, it.t));
	it.normal = vec3_normalized(vec3_sub(it.point, vec3_add(cy.cap_c, vec3_scale(cy.vec_inver, aux.m)))); p - (c + v*m);
} */

/* 		if (it1.m < 0 || it1.m > cy.h && it2.m < 0 || it2.m > cy.h) //se nenhum dos pontos de intersecao esta nos limites da altura do cilindro
			return(it1.inter = false, it1);
		if (it1.m >= 0 && it1.m <= cy.h && it2.m >= 0 && it2.m <= cy.h) //se ambos os pontos de intersecao estao no cilindro
			it1 = closer_inter(it1, it2);               
		else if (it1.m >= 0 && it1.m <= cy.h) //se apenas o m1 esta no cilindro
			it1 = closer_inter(it1, it2);
		else
			it1 = closer_inter(it1, it2); */
