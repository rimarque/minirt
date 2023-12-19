/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:54:05 by rita              #+#    #+#             */
/*   Updated: 2023/12/19 21:48:39 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "../libftx/includes/libft.h"

# define ESC 65307
# define COLOR 0x00AAFF
# define ANGLE 120
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define SCALE 0.4

typedef struct s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				height;
	int				width;
	double			zoom;
}		t_win;

void test();
t_win	new_program(int w, int h, char *str);
int		close_window(t_win *win);
int		handle_key_event(int button, t_win *view);

#endif