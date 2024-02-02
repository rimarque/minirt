/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:54:05 by rita              #+#    #+#             */
/*   Updated: 2024/02/02 21:47:11 by rita             ###   ########.fr       */
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

typedef struct s_auxeq
{
	float	in_sqrt;
	float	t1;
	float	t2;
	float	m;
	float	dot_dv;
	float	dot_cov;
}t_auxeq;

typedef struct s_inter
{
	bool	inter;
	t_vec3	point;
	float	t;  //distancia a origem do ray
	int		i;
	t_vec3	normal;
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

//*RENDER
void	render(t_img img, t_scene sc);

//*INTER_PL
t_inter	inter_pl(t_ray ray, t_obj pl, t_inter prev_it);

//*INTER_SP
float	closer_t(t_auxeq aux);
t_inter	inter_sp(t_ray ray, t_obj sp, t_inter prev_it);

//*INTER_CY
t_inter inter_cy(t_ray ray, t_obj cy, t_inter prev_it);

//*GET
t_vec3  get_dir(t_vec2 pixel, t_cam cam);
t_mt    get_camaxis(t_vec3 view, t_vec3 o);
t_mt    get_cyaxis(t_vec3 normal, t_vec3 o);
void    set_coord(t_vec3 *vec, float a, float b, float c);
void    set_color(t_rgb *color, uint8_t r, uint8_t g, uint8_t b);

#endif