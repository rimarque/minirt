/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:35:37 by rita              #+#    #+#             */
/*   Updated: 2024/02/02 20:14:36 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_inter	inter_pl(t_ray ray, t_obj pl, t_inter prev_it)
{
	t_inter it;
	float	dot_dv;

	dot_dv = vec3_dot(vec3_normalized(ray.d), pl.vector);
	/* if(dot_dv == 0)
	{
		//!testar
		//se estiver na mesma linha que o plano temos de ver um ponto
		//verificar se o raio interseta o ponto do plano
		if(inter_point(ray, pl.point))
		{
			it.t = 1;
			it.point = vec3_add(ray.o, ray.d);
			it.normal = pl.vector;
			return(it.inter = true, it);
		}
		return(it.inter = false, it);
	} */	
	it.t = vec3_dot(vec3_sub(pl.point, ray.o), pl.vector) / dot_dv;
	if(it.t < 0 || (prev_it.inter && prev_it.t < it.t))
    {
		it.inter = false;
		return(it);
	}
	it.point = vec3_add(ray.o, vec3_scale(ray.d, it.t));
	it.inter = true;
	if(dot_dv < 0)
	{
		printf("entra aqui\n");
		it.normal = vec3_scale(pl.vector, -1);
	}
	else
		it.normal = pl.vector;
	return(it);
}