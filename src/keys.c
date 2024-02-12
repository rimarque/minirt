/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:47:42 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/12 21:38:35 by rita             ###   ########.fr       */
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
	if (img->id_obj == 0)
		translate_cam(img, button);
	else
		translate_obj(img->scene->obj, img->id_obj - 1, button);
}

void	rotate(t_img *img, int button)
{
	if (img->id_obj == 0)
		rotate_cam(img, button);
	else
	{
		if(img->scene->obj[img->id_obj - 1].type == SP)
			return ;
		rotate_obj(img->scene->obj, img->id_obj - 1, button);
	}
		
}

void	reset_img(t_img *img)
{
	ft_free_scene(img->scene);
	init_scene(img->scene);
	copy_scene(img->scene, *img->original_scene);
	render(*img, *img->scene);
	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);
}

/* void	set_obj_id_mode(bool *object_mode, int *id, int n_obj)
{
	*id = (*id + 1) % (n_obj + 1);
	if(*id == 0)
		*object_mode = false;
	else
		*object_mode = true;
}*/

t_rgb   get_color(uint8_t r, uint8_t g, uint8_t b)
{
	t_rgb	color;

    color.r = r;
    color.g = g;
    color.b = b;
	return (color);
}

//todo: translate light
int	handle_key_event(int button, t_img *img)
{
    //printf("Button: %d\n", button);
	if (button == ESC)
		close_window(img);
	if(button == TAB)
	{
		if(img->id_obj > 0)
		{
			img->scene->obj[img->id_obj - 1].c = 
			img->original_scene->obj[img->id_obj - 1].c;
		}
		img->id_obj = (img->id_obj + 1) % (img->scene->n_obj + 1);
		if(img->id_obj > 0)
			img->scene->obj[img->id_obj - 1].c = get_color(255, 0, 0);
	}
	if(is_rotation_button(button))
		rotate(img, button);
	if(is_translation_button(button))
		translate(img, button);
	if(button == R)
		reset_img(img);
	render(*img, *img->scene);
	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);
	return (0);
}
