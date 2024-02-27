/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:54:00 by rita              #+#    #+#             */
/*   Updated: 2024/02/27 11:04:14 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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

bool	aply_quadratic_form(float a, float b, float c, t_auxqf *aux)
{
	aux->in_sqrt = b * b - 4 * a * c;
	if (aux->in_sqrt < 0)
		return (false);
	aux->t1 = (-b + sqrtf(aux->in_sqrt)) / (2 * a);
	aux->t2 = (-b - sqrtf(aux->in_sqrt)) / (2 * a);
	return (true);
}