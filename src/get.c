/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:16:21 by rita              #+#    #+#             */
/*   Updated: 2024/01/01 18:33:44 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

//primary ray's direction
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