/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:32:56 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/07 18:24:41 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_win	new_program(char *title)
{
	void	*mlx_ptr;
	t_win	win;

	mlx_ptr = mlx_init();
	win.mlx_ptr = mlx_ptr;
	win.win_ptr = mlx_new_window(mlx_ptr, WIN_W, WIN_H, title);
	return (win);
}

t_img	new_img(t_win *win, t_scene scene)
{
	t_img img;

	img.ptr = mlx_new_image(win->mlx_ptr, WIN_W,
			WIN_H);
	img.addr = mlx_get_data_addr(img.ptr,
			&img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.win = win;
	img.scene = scene;
	return(img);
}