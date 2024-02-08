/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:42:01 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/08 19:43:53 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	close_window(t_img *img)
{
	ft_free_scene(img->scene);
	//ft_free_scene(img->original_scene);
	mlx_destroy_image(img->win->mlx_ptr, img->ptr);
	mlx_destroy_window(img->win->mlx_ptr, img->win->win_ptr);
	if (OS == 1)
	   mlx_destroy_display(img->win->mlx_ptr);
	free(img->win->mlx_ptr);
	exit(0);
}
