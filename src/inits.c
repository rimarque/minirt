/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:32:56 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/08 12:43:02 by rita             ###   ########.fr       */
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

t_img	new_img(t_win *win, t_scene *scene, t_rotation rot)
{
	t_img img;

	img.ptr = mlx_new_image(win->mlx_ptr, WIN_W,
			WIN_H);
	img.addr = mlx_get_data_addr(img.ptr,
			&img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.win = win;
	img.scene = scene;
	img.rot = rot;
	return(img);
}

t_rotation init_rot_matrix()
{
	t_rotation	rot;

	rot.x_pos = get_rotmatrix_x(ANG_ROT_POS);
	rot.x_neg = get_rotmatrix_x(ANG_ROT_NEG);
	rot.y_pos = get_rotmatrix_y(ANG_ROT_POS);
	rot.y_neg = get_rotmatrix_y(ANG_ROT_NEG);
	rot.z_pos = get_rotmatrix_z(ANG_ROT_POS);
	rot.z_neg = get_rotmatrix_z(ANG_ROT_NEG);
	return(rot);
}

void	init_program(t_img *img, t_scene *scene, char *title, t_win *win)
{
	t_rotation	rot;
	
	*win = new_program(title);
	rot = init_rot_matrix();
    *img = new_img(win, scene, rot);
}