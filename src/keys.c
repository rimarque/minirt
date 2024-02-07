/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:47:42 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/07 19:18:01 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	handle_key_event(int button, t_img *view)
{
    printf("Button: %d\n", button);
	if (button == ESC)
		close_window(view);
/* 	if(button = R)
		render(*view, view->scene); */
	return (0);
}
