/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:32:56 by bde-sous          #+#    #+#             */
/*   Updated: 2023/12/19 20:35:47 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_win	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;
	t_win	win;

	mlx_ptr = mlx_init();
	win.mlx_ptr = mlx_ptr;
	win.win_ptr = mlx_new_window(mlx_ptr, w, h, str);
	win.width = w;
	win.height = h;
	win.zoom = 150.0;
	return (win);
}