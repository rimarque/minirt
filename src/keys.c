/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:47:42 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/08 21:55:18 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

//Botao de reset
//Condicoes para que a rotacao funcione em todas as direçoes
//cam (0, 0, -1);
int	handle_key_event(int button, t_img *img)
{
    printf("Button: %d\n", button);
	if (button == ESC)
		close_window(img);
	if(button == D)
	{
		//ft_print_scene(img->scene);
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rot.x_neg);
		render(*img, *img->scene);
	}
	if(button == UP)
	{
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rot.x_pos);
		render(*img, *img->scene);
		mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);
	}
	if(button == DOWN)
	{
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rot.x_neg); //baixo
		render(*img, *img->scene);
		mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);
	}
	if(button == RIGHT)
	{
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rot.y_neg); //direita
		render(*img, *img->scene);
		mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);
	}
	if(button == LEFT)
	{
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rot.y_pos); //esquerda
		render(*img, *img->scene);
		mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);
	}
	if(button == RESET)
	{
		img->scene = img->original_scene;
		render(*img, *img->scene);
		mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);
	}
	return (0);
}
