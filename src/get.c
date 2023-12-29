/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:16:21 by rita              #+#    #+#             */
/*   Updated: 2023/12/29 17:48:40 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

t_vec3  get_dir(t_vec2 pixel, t_cam cam)
{
    t_vec3 result;

    float x_max;
    float y_max;
    x_max = tanf(cam.fov_x/2);
    y_max = x_max * cam.aspect; //tan(fov_y / 2) = tan(fov_x / 2) * aspect;
    result.x = pixel.x * x_max;
    result.y = pixel.y * y_max;
    result.z = -1;
    return(result);
}