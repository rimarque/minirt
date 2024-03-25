/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:05:05 by rita              #+#    #+#             */
/*   Updated: 2024/02/26 22:20:24 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	is_red(t_rgb color)
{
	if (color.r > 200 && color.g < 80 && color.b < 80)
		return (true);
	return (false);
}

void	select_obj(t_img *img, t_obj *obj, t_obj *original_obj, int n_obj)
{
	img->height_mode = 0;
	if (img->obj_id > 0)
	{
		obj[img->obj_id - 1].color = original_obj[img->obj_id - 1].color;
	}
	img->obj_id = (img->obj_id + 1) % (n_obj + 1);
	if (img->obj_id > 0)
	{
		if (is_red(obj[img->obj_id - 1].color))
			obj[img->obj_id - 1].color = get_color(128, 128, 128);
		else
			obj[img->obj_id - 1].color = get_color(255, 0, 0);
	}
	render(*img, *img->scene);
	mlx_put_image_to_window(img->win->mlx_ptr, \
		img->win->win_ptr, img->ptr, 0, 0);
}

void	reset_obj_selection(t_img *img)
{
	img->scene->obj[img->obj_id - 1].color = \
		img->original_scene->obj[img->obj_id - 1].color;
	img->obj_id = 0;
	img->height_mode = 0;
	render(*img, *img->scene);
	mlx_put_image_to_window(img->win->mlx_ptr, \
		img->win->win_ptr, img->ptr, 0, 0);
}

void	set_mode(bool *mode)
{
	if (*mode == true)
		*mode = false;
	else if (*mode == false)
		*mode = true;
}

void	select_mode(int button, t_img *img)
{
	if (button == TAB && img->light_mode == false)
	{
		select_obj(img, img->scene->obj, img->original_scene->obj, \
			img->scene->n_obj);
	}
	if (button == L)
	{
		if (img->light_mode == false && img->obj_id > 0)
			reset_obj_selection(img);
		set_mode(&img->light_mode);
	}
	if (button == H && img->obj_id > 0 && \
			img->scene->obj[img->obj_id - 1].type == CY)
		set_mode(&img->height_mode);
}
