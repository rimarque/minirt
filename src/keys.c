/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:47:42 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/08 13:00:58 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

//cam (0, 0, -1);
int	handle_key_event(int button, t_img *img)
{
    printf("Button: %d\n", button);
	if (button == ESC)
		close_window(img);
	if(button == D)
	{
		//ft_print_scene(img->scene);
		img->scene->cam->axis = mltmatrix(img->scene->cam->axis, img->rot.x_neg);
		render(*img, *img->scene);
	}
	return (0);
}
