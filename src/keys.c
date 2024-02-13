/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:47:42 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/13 12:41:23 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

bool	is_translation_button(int button)
{
	if(button == W || button == S || button == A 
	|| button == D || button == SHIFT_LEFT || button == CTRL_LEFT)
		return(true);
	return(false);
}

bool	is_rotation_button(int button)
{
	if(button == UP || button == DOWN || button == RIGHT 
	|| button == LEFT || button == SHIFT_RIGHT || button == CTRL_RIGHT)
		return(true);
	return(false);
}

void	translate(t_img *img, int button)
{	
	if(img->light_mode == true)
		translate_light(img->scene->light, button);
	else if (img->obj_id == 0)
		translate_cam(img, button);
	else
		translate_obj(img->scene->obj, img->obj_id - 1, button);
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
		rotate_obj(img->scene->obj, img->obj_id - 1, button);
	}
	render(*img, *img->scene);
	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);	
}

void	reset_img(t_img *img)
{
	ft_free_scene(img->scene);
	init_scene(img->scene);
	copy_scene(img->scene, *img->original_scene);
	render(*img, *img->scene);
	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);
}

void	set_obj_id(t_img *img, t_obj *obj, t_obj *original_obj, int n_obj)
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

void	set_light_mode(bool *light_mode)
{
	if(*light_mode == true)
		*light_mode = false;
	else if(*light_mode == false)
		*light_mode = true;
}

//todo: resize obj
//todo: adicional calcul
int	handle_key_event(int button, t_img *img)
{
    printf("Button: %d\n", button);
	if (button == ESC)
		close_window(img);
	if(button == TAB)
		set_obj_id(img, img->scene->obj, img->original_scene->obj, 
			img->scene->n_obj);
	if(button == L)
		set_light_mode(&img->light_mode);		
	if(is_rotation_button(button))
		rotate(img, button);
	if(is_translation_button(button))
		translate(img, button);
	if(button == R)
		reset_img(img);
	return (0);
}
