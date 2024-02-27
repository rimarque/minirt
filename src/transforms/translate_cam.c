/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:00:31 by rita              #+#    #+#             */
/*   Updated: 2024/02/26 22:01:54 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	translate_cam_y(t_cam *cam, float amount)
{
	cam->view_point = vec3_add(cam->view_point, 
	vec3_scale(cam->axis.y, amount));
}

void	translate_cam_x(t_cam *cam, float amount)
{
	cam->view_point = vec3_add(cam->view_point, 
	vec3_scale(cam->axis.x, amount));
}

void	translate_cam_z(t_cam *cam, float amount)
{
	cam->view_point = vec3_add(cam->view_point, 
	vec3_scale(cam->axis.z, amount));
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