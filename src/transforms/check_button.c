/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:55:58 by rita              #+#    #+#             */
/*   Updated: 2024/02/13 21:20:31 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	is_change_mode(int button)
{
	if (button == TAB || button == L || button == H)
		return(true);
	return(false);
}

bool	is_resize(int button, int obj_id, t_obj *obj)
{
	if (obj_id > 0 && obj[obj_id - 1].type != PL
		&& (button == INCREASE || button == DECREASE))
		return(true);
	return(false);
}

bool	is_rotation(int button)
{
	if(button == UP || button == DOWN || button == RIGHT 
		|| button == LEFT || button == SHIFT_RIGHT 
			|| button == CTRL_RIGHT)
		return(true);
	return(false);
}

bool	is_translation(int button)
{
	if(button == W || button == S || button == A 
		|| button == D || button == SHIFT_LEFT 
			|| button == CTRL_LEFT)
		return(true);
	return(false);
}