/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:00:13 by rita              #+#    #+#             */
/*   Updated: 2024/02/26 18:29:11 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	translate_obj(t_obj *obj, int button)
{
	translate_point(&obj->point, button);
	if(obj->type == CY)
		compute_cy_aux_var(obj);
}

void	translate(t_img *img, int button)
{	
	if(img->light_mode == true)
		translate_point(&img->scene->light->point, button);
	else if (img->obj_id == 0)
		translate_cam(img, button);
	else
		translate_obj(&img->scene->obj[img->obj_id -1], button);
	render(*img, *img->scene);
	mlx_put_image_to_window(img->win->mlx_ptr, 
    	img->win->win_ptr, img->ptr, 0, 0);
}

void	rotate(t_img *img, int button)
{
	if(img->light_mode == true)
		return ;
	if (img->obj_id == 0)
		rotate_cam(img, button);
	else
	{
		if(img->scene->obj[img->obj_id - 1].type == SP)
			return ;
		rotate_obj(&img->scene->obj[img->obj_id - 1], button);
	}
	render(*img, *img->scene);
	mlx_put_image_to_window(img->win->mlx_ptr, 
        img->win->win_ptr, img->ptr, 0, 0);	
}