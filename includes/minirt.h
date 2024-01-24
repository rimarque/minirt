/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:54:05 by rita              #+#    #+#             */
/*   Updated: 2024/01/24 19:21:10 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H


# include "../mlx/mlx.h"
# include "./map_validation.h"

# define ESC 65307
# define PI 3.1415
# define ANG_ROT PI/8
# define WIN_W 1280
# define WIN_H 700
# define PL 0
# define SP 1
# define CY 2
# define BEGIN_IMAGE_LOOP(img) int i =0; int j=0; while(i<WIN_W){j=0;while(j<WIN_H){
# define END_IMAGE_LOOP j++;}i++;}

typedef struct s_inter
{
	bool	inter;
	t_vec3	point;
	float	t;  //distancia a origem do ray
	int		i;
} t_inter;

typedef struct s_ray
{
	t_vec3 d;
	t_vec3 o;
}t_ray;

typedef struct s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	
}		t_win;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_win	*win;
}t_img;

//*INITS
t_win	new_program(char *title);
t_img	new_img(t_win *win);

//*EXIT
int		close_window(t_img *img);

//*KEYS
int		handle_key_event(int button, t_img *view);

//*CREATE IMG
void	draw_test(t_img img);
void render(t_img img, t_scene sc);

//*GET
t_vec3  get_dir(t_vec2 pixel, t_cam cam);
t_mt    get_axis(t_vec3 view, t_vec3 o);
void    set_coord(t_vec3 *vec, float a, float b, float c);
void    set_color(t_rgb *color, uint8_t r, uint8_t g, uint8_t b);

#endif