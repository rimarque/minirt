/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:47:42 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/09 18:06:44 by rita             ###   ########.fr       */
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

void	rotate_cam_up(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_pos);
	if(cam.normal.x == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_neg);
	if(cam.normal.y == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_neg);
	if(cam.normal.y == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_pos);
	if(cam.normal.z == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_neg);
	if(cam.normal.z == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_pos);
}

void	rotate_cam_down(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_neg);
	if(cam.normal.x == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_pos);
	if(cam.normal.y == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_pos);
	if(cam.normal.y == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_neg);
	if(cam.normal.z == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_pos);
	if(cam.normal.z == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_neg);
}

void	rotate_cam_right(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_neg);
	if(cam.normal.x == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_neg);
	if(cam.normal.y == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_neg);
	if(cam.normal.y == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_neg);
	if(cam.normal.z == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_neg);
	if(cam.normal.z == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_neg);
}

void	rotate_cam_left(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_pos);
	if(cam.normal.x == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_pos);
	if(cam.normal.y == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_pos);
	if(cam.normal.y == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_pos);
	if(cam.normal.z == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_pos);
	if(cam.normal.z == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_pos);
}

void	rot_cam_clockwise(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_pos);
	if(cam.normal.x == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_neg);
	if(cam.normal.y == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_pos);
	if(cam.normal.y == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_neg);
	if(cam.normal.z == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_pos);
	if(cam.normal.z == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_neg);
}

void	rot_cam_counterclock(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_neg);
	if(cam.normal.x == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_pos);
	if(cam.normal.y == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_neg);
	if(cam.normal.y == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_pos);
	if(cam.normal.z == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_neg);
	if(cam.normal.z == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_pos);
}

void	rotate_cam(t_img *img, int button)
{
	if(button == UP)
		rotate_cam_up(img, *img->scene->cam);
	if(button == DOWN)
		rotate_cam_down(img, *img->scene->cam);
	if(button == RIGHT)
		rotate_cam_right(img, *img->scene->cam);
	if(button == LEFT)
		rotate_cam_left(img, *img->scene->cam);
	if(button == SHIFT_RIGHT)
		rot_cam_clockwise(img, *img->scene->cam);
	if(button == CTRL_RIGHT)
		rot_cam_counterclock(img, *img->scene->cam);
}


void	rotate(t_img *img, int button)
{
	/* if(img->object_mode)
		rotate_object();
	else */
		rotate_cam(img, button);
}

void	translate_cam_up(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.y_pos);
	if(cam.normal.x == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.y_pos);
	if(cam.normal.y == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.x_pos);
	if(cam.normal.y == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.x_pos);
	if(cam.normal.z == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.y_pos);
	if(cam.normal.z == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.y_pos);
}

void	translate_cam_down(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.y_neg);
	if(cam.normal.x == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.y_neg);
	if(cam.normal.y == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.x_neg);
	if(cam.normal.y == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.x_neg);
	if(cam.normal.z == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.y_neg);
	if(cam.normal.z == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.y_neg);
}

void	translate_cam_right(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.z_pos);
	if(cam.normal.x == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.z_neg);
	if(cam.normal.y == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.z_neg);
	if(cam.normal.y == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.z_pos);
	if(cam.normal.z == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.x_neg);
	if(cam.normal.z == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.x_pos);
}

void	translate_cam_left(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.z_neg);
	if(cam.normal.x == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.z_pos);
	if(cam.normal.y == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.z_pos);
	if(cam.normal.y == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.z_neg);
	if(cam.normal.z == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.x_pos);
	if(cam.normal.z == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.x_neg);
}

void	translate_cam_front(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.x_pos);
	if(cam.normal.x == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.x_neg);
	if(cam.normal.y == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.y_pos);
	if(cam.normal.y == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.y_neg);
	if(cam.normal.z == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.z_pos);
	if(cam.normal.z == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.z_neg);
}

void	translate_cam_back(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.x_neg);
	if(cam.normal.x == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.x_pos);
	if(cam.normal.y == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.y_neg);
	if(cam.normal.y == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.y_pos);
	if(cam.normal.z == 1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.z_neg);
	if(cam.normal.z == -1)
		img->scene->cam->axis.o = vec3_add(img->scene->cam->axis.o, img->translation.z_pos);
}

void	translate_cam(t_img *img, int button)
{
	if(button == SHIFT_LEFT)
		translate_cam_up(img, *img->scene->cam);
	if(button == CTRL_LEFT)
		translate_cam_down(img, *img->scene->cam);
	if(button == D)
		translate_cam_right(img, *img->scene->cam);
	if(button == A)
		translate_cam_left(img, *img->scene->cam);
	if(button == W)
		translate_cam_front(img, *img->scene->cam);
	if(button == S)
		translate_cam_back(img, *img->scene->cam);
}

void	translate(t_img *img, int button)
{
	/* if(img->object_mode)
		rotate_object();
	else */
		translate_cam(img, button);
}

void	reset_img(t_img *img)
{
	ft_free_scene(img->scene);
	init_scene(img->scene);
	copy_scene(img->scene, *img->original_scene);
	render(*img, *img->scene);
	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->ptr, 0, 0);
}

int	handle_key_event(int button, t_img *img)
{
    printf("Button: %d\n", button);
	if (button == ESC)
		close_window(img);
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
