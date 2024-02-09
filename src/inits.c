/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:32:56 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/09 17:40:49 by rita             ###   ########.fr       */
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

void	copy_scene(t_scene *dst, t_scene src)
{
	int		i;
	
	i = 0;
	dst->amb = malloc(sizeof(t_amb));
	*dst->amb = *src.amb;
	dst->cam = ft_calloc(1, sizeof(t_cam));
	*dst->cam = *src.cam;
	dst->light = ft_calloc(1, sizeof(t_light));
	*dst->light = *src.light;
	dst->n_obj = src.n_obj;
	dst->obj = (t_obj *)malloc(sizeof(t_obj) * dst->n_obj);
	while(i < dst->n_obj)
	{
		dst->obj[i] = src.obj[i];
		i++;
	}
}
t_rotation init_rot_matrix()
{
	t_rotation	rotation;

	rotation.x_pos = get_rotmatrix_x(ANG_ROT_POS);
	rotation.x_neg = get_rotmatrix_x(ANG_ROT_NEG);
	rotation.y_pos = get_rotmatrix_y(ANG_ROT_POS);
	rotation.y_neg = get_rotmatrix_y(ANG_ROT_NEG);
	rotation.z_pos = get_rotmatrix_z(ANG_ROT_POS);
	rotation.z_neg = get_rotmatrix_z(ANG_ROT_NEG);
	return(rotation);
}

t_translation	init_trans_vec()
{
	t_translation	translation;

	set_coord(&translation.x_pos, 1, 0, 0); 
	set_coord(&translation.x_neg, -1, 0, 0);
	set_coord(&translation.y_pos, 0, 1, 0);
	set_coord(&translation.y_neg, 0, -1, 0);
	set_coord(&translation.z_pos, 0, 0, 1);
	set_coord(&translation.z_neg, 0, 0, -1);
	return(translation);
}

t_img	new_img(t_win *win, t_scene *scene, t_scene *original_scene)
{
	t_img	img;
	
	img.ptr = mlx_new_image(win->mlx_ptr, WIN_W,
			WIN_H);
	img.addr = mlx_get_data_addr(img.ptr,
			&img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.win = win;
	img.scene = scene;
	copy_scene(original_scene, *scene);
	img.original_scene = original_scene;
	img.rotation = init_rot_matrix();
	img.translation = init_trans_vec();
	return(img);
}


void	init_program(t_img *img, t_scene *scene, t_scene *original_scene, t_win *win)
{
	*win = new_program("MINIRITA");
    *img = new_img(win, scene, original_scene);
}