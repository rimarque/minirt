/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:54:05 by rita              #+#    #+#             */
/*   Updated: 2024/02/09 11:39:04 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

#include "../mlx/mlx.h"
#include "./map_validation.h"

#ifndef OS
#define OS 1
#endif

#if OS == 1
#define ESC 65307
#define LEFT 65361
#define RIGHT 65363
#define UP 65362
#define DOWN 65364
#define W 119
#define A 97
#define S 115
#define D 100
#define O 111
#define INCREASE 65451
#define DECREASE 65453
#define RESET 114
#elif OS == 2
#define ESC 53
#define LEFT 123
#define RIGHT 124
#define UP 126
#define DOWN 125
#define W 13
#define A 0
#define S 1
#define D 2
#define O 31
#define INCREASE 24
#define DECREASE 27
#define RESET 15
#endif

#define PI 3.1415
#define ANG_ROT_POS PI / 64
#define ANG_ROT_NEG -ANG_ROT_POS
#define WIN_W 1280
#define WIN_H 700
#define PL 0
#define SP 1
#define CY 2

typedef struct s_rotation {
  t_matrix x_pos;
  t_matrix x_neg;
  t_matrix y_pos;
  t_matrix y_neg;
  t_matrix z_pos;
  t_matrix z_neg;
} t_rotation;

typedef struct s_auxeq {
  float in_sqrt;
  float t1;
  float t2;
  float dot_dv;
  float dot_cov;
} t_auxeq;

typedef struct s_inter {
  bool inter;
  int i;
  float t;
  float m;
  t_vec3 point;
  t_vec3 normal;
} t_inter;

typedef struct s_ray {
  t_vec3 d;
  t_vec3 o;
} t_ray;

typedef struct s_win {
  void *mlx_ptr;
  void *win_ptr;

} t_win;

typedef struct s_img
{
	void		*ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_win		*win;
	t_scene		*scene;
	t_rotation	rot;
	t_scene		*original_scene;
}t_img;

//*INITS
t_win	new_program(char *title);
t_img	new_img(t_win *win, t_scene *scene, t_scene *original_scene, t_rotation rot);
void	init_program(t_img *img, t_scene *scene, t_scene *original_scene, t_win *win);
void	copy_scene(t_scene *dst, t_scene src);

//*EXIT
int close_window(t_img *img);

//*KEYS
int handle_key_event(int button, t_img *view);

//*RENDER
void render(t_img img, t_scene sc);

//*CAM
t_matrix cam_axis(t_vec3 view, t_vec3 o);
t_ray get_ray(int i, int j, t_scene sc);

//*INTERSECT
t_inter intersect(t_ray ray, t_obj *obj, int n);

//*INTER_PL
t_inter inter_pl(t_ray ray, t_obj pl, t_inter prev_it);

//*INTER_SP
t_inter inter_sp(t_ray ray, t_obj sp, t_inter prev_it);

//*INTER_CY
t_inter inter_cy(t_ray ray, t_obj cy, t_inter prev_it);

//*INTER_CYSURFACE
t_inter inter_surface(t_ray ray, t_obj cy);

//*INTER_CYBASE
t_inter inter_base(t_ray ray, t_obj cy);

//*INTER_CLOSER
t_inter closer_inter(t_inter it1, t_inter it2);
float closer_t(float in_sqrt, float t1, float t2);

//*LIGHT
float compute_light(t_scene *scene, t_inter *it);

#endif
