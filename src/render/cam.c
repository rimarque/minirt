/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:16:21 by rita              #+#    #+#             */
/*   Updated: 2024/02/13 20:03:06 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_matrix	cam_axis(t_vec3 view)
{
	t_matrix	axis;
	t_vec3		up;

	set_coord(&up, 0, 1, 0);
	if (vec3_dot(up, view) == 1 || vec3_dot(up, view) == -1)
		set_coord(&up, 1, 0, 0);
	axis.z = vec3_scale(view, -1);
	axis.x = vec3_normalized(vec3_cross(up, axis.z));
	axis.y = vec3_normalized(vec3_cross(axis.z, axis.x));
	return (axis);
}

t_vec3	ray_dir(float x, float y, t_cam cam)
{
	t_vec3	result;
	float	x_max;
	float	y_max;

	x_max = tanf(cam.fov_x / 2);
	y_max = x_max * cam.aspect;
	result.x = x * x_max;
	result.y = y * y_max;
	result.z = -1;
	result = vec3_normalized(result);
	result = vec3_mltmatrix(cam.axis, result);
	return (result);
}

t_ray	get_ray(int i, int j, t_scene sc)
{
	float	x;
	float	y;
	t_ray	ray;

	j = WIN_H - j - 1;
	x = ((float)i / (WIN_W - 1)) * 2 - 1;
	y = ((float)j / (WIN_H - 1)) * 2 - 1;
	ray.d = ray_dir(x, y, *sc.cam);
	ray.o = sc.cam->view_point;
	return (ray);
}
