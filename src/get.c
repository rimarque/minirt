/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:16:21 by rita              #+#    #+#             */
/*   Updated: 2024/01/17 16:01:27 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

//tan(fov_y / 2) = tan(fov_x / 2) * aspect;
t_vec3  get_dir(t_vec2 pixel, t_cam cam)
{
    t_vec3 result;

    float x_max;
    float y_max;
    x_max = tanf(cam.fov_x/2);
    y_max = x_max * cam.aspect; 
    result.x = pixel.x * x_max;
    result.y = pixel.y * y_max;
    result.z = -1;
    result = vec3_mtpmt(result, cam.axis);
    result = vec3_sub(result, cam.o);
    result = vec3_normalized(result);
    //print_vec("dir:",result);
    //printf("point.x: %f\npoint.y: %f\npoint.z: %f\n", result.x, result.y, result.z);
    return(result);
}

void    set_coord(t_vec3 *vec, float a, float b, float c)
{
    vec->x = a;
    vec->y = b;
    vec->z = c;
}

void    set_color(t_rgb *color, uint8_t r, uint8_t g, uint8_t b)
{
    color->r = r;
    color->g = g;
    color->b = b;
}

//o up sera definido como (0,1,0); -> se o view for paralelo ao up: dot(normalized(up), normalized(view)) == 1 ou -1 -> up(1,0,0)??
t_mt    get_axis(t_vec3 view, t_vec3 o)
{
    t_mt  axis;
    t_vec3  up;

    set_coord(&up, 0, 1, 0);
    //if(vec3_dot(up, view) == 1 || vec3_dot(up, view) == -1) //!inventei nao sei se esta bem
    //    set_coords(&up, 1, 0, 0);
    axis.o = o;
    axis.z = vec3_scale(view, -1);
    axis.x = vec3_normalized(vec3_cross(up, axis.z));
    axis.y = vec3_normalized(vec3_cross(axis.z, axis.x));
    /* print_vec("X: ", axis.x);
    print_vec("Y: ", axis.y);
    print_vec("Z: ", axis.z); */
    return(axis);
}