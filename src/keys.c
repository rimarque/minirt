/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:47:42 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/09 12:50:26 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

bool	button_rotation(button)
{
	if(button == UP || button == DOWN || button == RIGHT || button == LEFT)
		return(true);
	return(false);
}

void	rotate(t_img *img, int button)
{
	if(img->object_mode)
		rotate_object
	if(button == UP)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rot.x_pos);
	if(button == DOWN)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rot.x_neg);
	if(button == RIGHT)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rot.y_neg);
	if(button == LEFT)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rot.y_pos);
	render(*img, *img->scene);
	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);
}


int	handle_key_event(int button, t_img *img)
{
    printf("Button: %d\n", button);
	if (button == ESC)
		close_window(img);
	if(button_rotation(button))
		rotate(img, button);
	if(button == RESET)
	{
		ft_free_scene(img->scene);
		init_scene(img->scene);
		copy_scene(img->scene, *img->original_scene);
		render(*img, *img->scene);
		mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);
	}
	return (0);
}
