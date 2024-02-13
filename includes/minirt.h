/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:54:05 by rita              #+#    #+#             */
/*   Updated: 2024/02/13 18:27:04 by rita             ###   ########.fr       */
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
#define SHIFT_RIGHT 65506
#define CTRL_RIGHT 65508
#define W 119
#define A 97
#define S 115
#define D 100
#define SHIFT_LEFT 65505
#define CTRL_LEFT 65507
#define TAB 65289
#define INCREASE 43
#define DECREASE 45
#define R 114
#define L 108
#define H 104
#elif OS == 2
#define ESC 53
#define LEFT 123
#define RIGHT 124
#define UP 126
#define DOWN 125
#define SHIFT_RIGHT
#define CTRL_RIGHT
#define W 13
#define A 0
#define S 1
#define D 2
#define SHIFT_LEFT
#define CTRL_RIGHT
#define TAB
#define INCREASE 24
#define DECREASE 27
#define R 15
#define L 
#define H
#endif

#define PI 3.1415
#define ANG_ROT PI / 32
#define SCALE_TRANS 4
#define RESIZE_R 0.1
#define RESIZE_H 0.2
#define WIN_W 1280
#define WIN_H 700
#define PL 0
#define SP 1
#define CY 2

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
	void          *ptr;
	char          *addr;
	int           bits_per_pixel;
	int			      line_length;
	int			      endian;
	t_win         *win;
	t_scene		    *scene;
	t_scene		    *original_scene;
  bool          light_mode;
  bool          height_mode;
  int           obj_id;
}t_img;

//*INITS
t_win	new_program(char *title);
t_img	new_img(t_win *win, t_scene *scene, t_scene *original_scene);
void	copy_scene(t_scene *dst, t_scene src);

//*EXIT
int close_window(t_img *img);

//*KEYS
int handle_key_event(int button, t_img *view);

//*ROTATE_CAM
void	rotate_cam(t_img *img, int button);

//*ROTATE_OBJ
void    rotate_obj(t_obj *obj, int button);

//*TRANSLATE_CAM
void	translate_cam(t_img *img, int button);

//*TRANSLATE_POINT
void	translate_point(t_vec3 *point, int button);
void	translate_obj(t_obj *obj, int button);

//*RESIZE_OBJ
void	resize_obj(t_img *img, int button, t_obj *obj);

//*AUX_OBJ
void    compute_auxvariables(t_obj *obj);
t_rgb   get_color(uint8_t r, uint8_t g, uint8_t b);

//*RENDER
void render(t_img img, t_scene sc);

//*CAM
t_matrix    cam_axis(t_vec3 view);
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
