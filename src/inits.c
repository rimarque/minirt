/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:32:56 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/13 11:45:07 by rita             ###   ########.fr       */
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
	img.obj_id = 0;
	img.light_mode = false;
	return(img);
}