/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-18 19:35:02 by bde-sous          #+#    #+#             */
/*   Updated: 2024-03-18 19:35:02 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ft_print_amb(t_amb *amb)
{
	printf("---AMBIENTE---\n\n");
	printf("ratio:      %f\n", amb->ratio);
	ft_print_color(&amb->c);
	printf("\n\n");
}

void	ft_print_cam(t_cam *cam)
{
	printf("---CAMARA---\n\n");
	printf("view_point\n");
	ft_print_vec(&cam->view_point);
	printf("FOV X:      %f\n", cam->fov_x);
	printf("\nCAMARA AXIS:\n");
	print_vec("X:      ", cam->axis.x);
	print_vec("Y:      ", cam->axis.y);
	print_vec("Z:      ", cam->axis.z);
	printf("\n\n");
}

void	ft_print_light(t_light *light)
{
	printf("---LIGHT---\n\n");
	printf("point\n");
	ft_print_vec(&light->point);
	printf("Ratio:      %f\n", light->ratio);
	printf("\n\n");
}

void	ft_print_scene(t_scene *scene)
{
	ft_print_amb(scene->amb);
	ft_print_cam(scene->cam);
	ft_print_light(scene->light);
	ft_print_obj(scene->obj, scene->n_obj);
}
