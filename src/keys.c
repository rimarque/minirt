/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:47:42 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/13 21:05:39 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	handle_key_event(int button, t_img *img)
{
    //printf("Button: %d\n", button);
	if (button == ESC)
		close_window(img);
	if(is_change_mode(button))
		select_mode(button, img);
	if(is_resize(button, img->obj_id, img->scene->obj))
		resize_obj(img, button, &img->scene->obj[img->obj_id - 1]);
	if(is_rotation(button))
		rotate(img, button);
	if(is_translation(button))
		translate(img, button);
	if(button == R)
		reset_img(img);
	return (0);
}
