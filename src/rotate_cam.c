/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:57:52 by rita              #+#    #+#             */
/*   Updated: 2024/02/12 14:11:07 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	rotate_cam_x(t_cam	*cam, float	ang)
{
	cam->axis = matrix_mltmatrix(cam->axis, get_rotmatrix_x(ang));
}

void	rotate_cam_y(t_cam	*cam, float	ang)
{
	cam->axis = matrix_mltmatrix(cam->axis, get_rotmatrix_y(ang));
}

void	rotate_cam_z(t_cam	*cam, float	ang)
{
	cam->axis = matrix_mltmatrix(cam->axis, get_rotmatrix_z(ang));
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
