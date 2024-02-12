/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:47:42 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/12 11:47:54 by rita             ###   ########.fr       */
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

void	rotate_cam_x(t_cam	*cam, float	ang)
{
	cam->axis = rot_axis(cam->axis, get_rotmatrix_x(ang));
}

void	rotate_cam_y(t_cam	*cam, float	ang)
{
	cam->axis = rot_axis(cam->axis, get_rotmatrix_y(ang));
}

void	rotate_cam_z(t_cam	*cam, float	ang)
{
	cam->axis = rot_axis(cam->axis, get_rotmatrix_z(ang));
}

void	rotate_cam(t_img *img, int button)
{
	if(button == UP)
		rotate_cam_x(img->scene->cam, ANG_ROT);
	if(button == DOWN)
		rotate_cam_x(img->scene->cam, -ANG_ROT);
	if(button == RIGHT)
		rotate_cam_y(img->scene->cam, -ANG_ROT);
	if(button == LEFT)
		rotate_cam_y(img->scene->cam, ANG_ROT);
	if(button == SHIFT_RIGHT)
		rotate_cam_z(img->scene->cam, -ANG_ROT);
	if(button == CTRL_RIGHT)
		rotate_cam_z(img->scene->cam, ANG_ROT);
}


void	rotate(t_img *img, int button)
{
	/* if(img->object_mode)
		rotate_object();
	else */
		rotate_cam(img, button);
}

void	translate_cam_y(t_cam *cam, float amount)
{
	cam->view_point = vec3_add(cam->view_point, vec3_scale(cam->axis.y, amount));
}

void	translate_cam_x(t_cam *cam, float amount)
{
	cam->view_point = vec3_add(cam->view_point, vec3_scale(cam->axis.x, amount));
}

void	translate_cam_z(t_cam *cam, float amount)
{
	cam->view_point = vec3_add(cam->view_point, vec3_scale(cam->axis.z, amount));
}


void	translate_cam(t_img *img, int button)
{
	if(button == SHIFT_LEFT)
		translate_cam_y(img->scene->cam, SCALE_TRANS);
	if(button == CTRL_LEFT)
		translate_cam_y(img->scene->cam, -SCALE_TRANS);
	if(button == D)
		translate_cam_x(img->scene->cam, SCALE_TRANS);
	if(button == A)
		translate_cam_x(img->scene->cam, -SCALE_TRANS);
	if(button == W)
		translate_cam_z(img->scene->cam, -SCALE_TRANS);
	if(button == S)
		translate_cam_z(img->scene->cam, SCALE_TRANS);
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
