/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:42:01 by bde-sous          #+#    #+#             */
/*   Updated: 2023/12/26 21:00:00 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	close_window(t_img *img)
{
	//free_info(info);
	mlx_destroy_image(img->win->mlx_ptr, img->ptr);
	mlx_destroy_window(img->win->mlx_ptr, img->win->win_ptr);
	if (OS == 1)
	   mlx_destroy_display(img->win->mlx_ptr);
	free(img->win->mlx_ptr);
	exit(0);
}
