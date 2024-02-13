/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:00:31 by rita              #+#    #+#             */
/*   Updated: 2024/02/13 11:53:22 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	translate_light_y(t_light *light, float scale)
{
	t_vec3	dir;

	set_coord(&dir, 0, 1, 0);
	light->point = vec3_add(light->point, 
	vec3_scale(dir, scale));	
}

void	translate_light_x(t_light *light, float scale)
{
	t_vec3	dir;

	set_coord(&dir, 1, 0, 0);
	light->point = vec3_add(light->point, 
	vec3_scale(dir, scale));
}

void	translate_light_z(t_light *light, float scale)
{
	t_vec3	dir;

	set_coord(&dir, 0, 0, 1);
	light->point = vec3_add(light->point, 
	vec3_scale(dir, scale));
}

void	translate_light(t_light *light, int button)
{
	if(button == SHIFT_LEFT)
		translate_light_y(light, SCALE_TRANS);
	if(button == CTRL_LEFT)
		translate_light_y(light, -SCALE_TRANS);
	if(button == D)
		translate_light_x(light, SCALE_TRANS);
	if(button == A)
		translate_light_x(light, -SCALE_TRANS);
	if(button == W)
		translate_light_z(light, -SCALE_TRANS);
	if(button == S)
		translate_light_z(light, SCALE_TRANS);
}