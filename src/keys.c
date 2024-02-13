/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:47:42 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/13 18:33:36 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

bool	is_translation(int button)
{
	if(button == W || button == S || button == A 
		|| button == D || button == SHIFT_LEFT 
			|| button == CTRL_LEFT)
		return(true);
	return(false);
}

bool	is_rotation(int button)
{
	if(button == UP || button == DOWN || button == RIGHT 
		|| button == LEFT || button == SHIFT_RIGHT 
			|| button == CTRL_RIGHT)
		return(true);
	return(false);
}

bool	is_resize(int button, int obj_id, t_obj *obj)
{
	if (obj_id > 0 && obj[obj_id - 1].type != PL
		&& (button == INCREASE || button == DECREASE))
		return(true);
	return(false);
}

bool	change_mode(int button)
{
	if (button == TAB || button == L || button == H)
		return(true);
	return(false);
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
	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);
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
	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);	
}

void	reset_mode(t_img *img)
{
	img->obj_id = 0;
	img->light_mode = 0;
	img->height_mode = 0;
}

void	reset_img(t_img *img)
{
	ft_free_scene(img->scene);
	init_scene(img->scene);
	copy_scene(img->scene, *img->original_scene);
	reset_mode(img);
	render(*img, *img->scene);
	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);
}


void	select_obj(t_img *img, t_obj *obj, t_obj *original_obj, int n_obj)
{
		if(img->obj_id > 0)
		{
			obj[img->obj_id - 1].color = 
			original_obj[img->obj_id - 1].color;
		}
		img->obj_id = (img->obj_id + 1) % (n_obj + 1);
		if(img->obj_id > 0)
			obj[img->obj_id - 1].color = get_color(255, 0, 0);
		render(*img, *img->scene);
		mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);
}

void	reset_obj_selection(t_img *img)
{
	img->scene->obj[img->obj_id - 1].color = 
			img->original_scene->obj[img->obj_id - 1].color;
	img->obj_id = 0;
	img->height_mode = 0;
	render(*img, *img->scene);
	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);
}

void	set_mode(bool *mode)
{
	if(*mode == true)
		*mode = false;
	else if(*mode == false)
		*mode = true;
}
void	select_mode(int button, t_img *img)
{
	if(button == TAB && img->light_mode == false)
		select_obj(img, img->scene->obj, img->original_scene->obj, 
			img->scene->n_obj);
	if(button == L)
	{
		if(img->light_mode == false && img->obj_id > 0)
			reset_obj_selection(img);
		set_mode(&img->light_mode);
	}
	if(button == H && img->obj_id > 0)
		set_mode(&img->height_mode);
}

//todo: resize obj
int	handle_key_event(int button, t_img *img)
{
    //printf("Button: %d\n", button);
	if (button == ESC)
		close_window(img);
	if(change_mode(button))
		select_mode(button, img);
	if(is_resize(button, img->obj_id, img->scene->obj))
		resize_obj(img, button, &img->scene->obj[img->obj_id - 1]);
	if(is_rotation(button))
		rotate(img, button);
	if(is_translation(button))
		translate(img, button);
	if(button == R)
		reset_img(img);
	return (0);
}
