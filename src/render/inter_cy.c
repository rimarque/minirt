/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:36:21 by rita              #+#    #+#             */
/*   Updated: 2024/02/13 19:48:15 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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
