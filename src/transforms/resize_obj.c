/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:37:17 by rita              #+#    #+#             */
/*   Updated: 2024/02/24 14:44:05 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void   resize_radius(t_obj *obj, int button)
{ 
	if(button == INCREASE)
		obj->r *= (1 + RESIZE_R);
	if(button == DECREASE)
		obj->r *= (1 - RESIZE_R);
	obj->r_sqr = obj->r * obj->r;
}

void   resize_height(t_obj *obj, int button)
{
	if(button == INCREASE)
		obj->h *= (1 + RESIZE_H);
	if(button == DECREASE)
		obj->h *= (1 - RESIZE_H);
	compute_auxvar_cy(obj); 
}

void	resize_obj(t_img *img, int button, t_obj *obj)
{
	if(img->height_mode == true)
	{
		if(obj->type == CY)
			resize_height(obj, button);
	}
	else
		resize_radius(obj, button);
	render(*img, *img->scene);
	mlx_put_image_to_window(img->win->mlx_ptr, 
		img->win->win_ptr, img->ptr, 0, 0);
}