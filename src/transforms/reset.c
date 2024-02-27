/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:58:43 by rita              #+#    #+#             */
/*   Updated: 2024/02/13 21:25:52 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	reset_mode(t_img *img)
{
	img->obj_id = 0;
	img->light_mode = 0;
	img->height_mode = 0;
}

void	reset_img(t_img *img)
{
	reset_mode(img);
	ft_free_scene(img->scene);
	init_scene(img->scene);
	copy_scene(img->scene, *img->original_scene);
	render(*img, *img->scene);
	mlx_put_image_to_window(img->win->mlx_ptr, 
        img->win->win_ptr, img->ptr, 0, 0);
}