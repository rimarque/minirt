/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:54:05 by rita              #+#    #+#             */
/*   Updated: 2024/02/27 11:31:56 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../mlx/mlx.h"
# include "./parser.h"

# ifndef OS
#  define OS 1
# endif

# if OS == 1
#  define ESC 65307
#  define LEFT 65361
#  define RIGHT 65363
#  define UP 65362
#  define DOWN 65364
#  define SHIFT_RIGHT 65506
#  define CTRL_RIGHT 65508
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define SHIFT_LEFT 65505
#  define CTRL_LEFT 65507
#  define TAB 65289
#  define INCREASE 65451
#  define DECREASE 65453
#  define R 114
#  define L 108
#  define H 104
# elif OS == 2
#  define ESC 53
#  define LEFT 123
#  define RIGHT 124
#  define UP 126
#  define DOWN 125
#  define SHIFT_RIGHT 258
#  define CTRL_RIGHT 256
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define SHIFT_LEFT 258
#  define CTRL_LEFT 256
#  define TAB 48
#  define INCREASE 24
#  define DECREASE 27
#  define R 15
#  define L 37
#  define H 4
# endif

# define PI 3.1415
# define ANG_ROT 0.098
# define SCALE_TRANS 4.0
# define LIGHT_RANGE 100.0
# define RESIZE_R 0.1
# define RESIZE_H 0.2
# define WIN_W 1280
# define WIN_H 700
# define PL 0
# define SP 1
# define CY 2

//*t_auxqf é uma estrutura auxiliar para a formula quadrática (fq)
// in_sqrt: parte da fq que é calculada dentro da raíz quadrada
// t1 e t2: distância à origem do raio de interseção
// dot_dv: produto interno entre d (direção do raio de interseção)
// e v (vetor do objeto)
// dot_cov: produto interno entre co (o-c, vetor com inicio no centro do objeto
// e término na origem do raio de interseção) e v (vetor do objeto)
typedef struct s_auxqf
{
	float	in_sqrt;
	float	t1;
	float	t2;
	float	dot_dv;
	float	dot_cov;
}	t_auxqf;

//*t_inter é a estrutura que guarda todas as variáveis
// relacionadas com a interseção entre raio e objeto
// inter: booleano que indica se existe ou não interseção
// i: índice do objeto intersecionado
// t: distância do ponto de interseção à origem do raio de interseção
// m: distância do centro da base1 do cilindro (base1_c) ao
// ponto no vetor do cilindro mais perto no ponto de interseção
//(permite saber se o ponto de interseção está dentro dos
// limites de altura do cilindro)
// point: ponto de interseção
// normal: normal da interseção
typedef struct s_inter
{
	bool	inter;
	int		i;
	float	t;
	float	m;
	t_vec3	point;
	t_vec3	normal;
}	t_inter;

//*t_ray é uma estrutura que reprensenta um raio
// uma semireta com origem e direção
// o: origem do raio
// d: direção do raio
typedef struct s_ray
{
	t_vec3	o;
	t_vec3	d;
}	t_ray;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;

}	t_win;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_win	*win;
	t_scene	*scene;
	t_scene	*original_scene;
	bool	light_mode;
	bool	height_mode;
	int		obj_id;
}	t_img;

//*INITS
t_win		new_program(char *title);
t_img		new_img(t_win *win, t_scene *scene, t_scene *original_scene);
void		init_scene(t_scene *scene);
void		copy_scene(t_scene *dst, t_scene src);

//*EXIT
int			close_window(t_img *img);

//*KEYS
int			handle_key_event(int button, t_img *view);

//*AUX_OBJ
t_rgb		get_color(uint8_t r, uint8_t g, uint8_t b);
void		compute_cy_aux_var(t_obj *cy);

/****************/
/*              */
/*    RENDER    */
/*              */
/****************/

//*RENDER
void		render(t_img img, t_scene sc);

//*CAM
t_matrix	cam_axis(t_vec3 view);
t_ray		get_ray(int i, int j, t_scene sc);

//*INTERSECT
t_inter		cam_ray_intersect_obj(t_ray ray, t_obj *obj, int n);
bool		lig_ray_int_obj(t_ray ray, t_scene scene, int avoid, float len_l);

//*INTER_PL
t_inter		inter_pl(t_ray ray, t_obj pl, t_inter prev_it);

//*INTER_SP
t_inter		inter_sp(t_ray ray, t_obj sp, t_inter prev_it);

//*INTER_CY
t_inter		inter_cy(t_ray ray, t_obj cy, t_inter prev_it);

//*INTER_CYSURFACE
t_inter		inter_surface(t_ray ray, t_obj cy);

//*INTER_CYBASE
t_inter		inter_base(t_ray ray, t_obj cy);

//*INTER_AUX
t_inter		closer_inter(t_inter it1, t_inter it2);
float		closer_t(float in_sqrt, float t1, float t2);
bool		aply_quadratic_form(float a, float b, float c, t_auxqf *aux);

//*LIGHT
float		compute_light(t_scene scene, t_inter it);

/******************/
/*                */
/*   TRANSFORMS   */
/*                */
/******************/

//*CHECK_BUTTON
bool		is_change_mode(int button);
bool		is_resize(int button, int obj_id, t_obj *obj);
bool		is_rotation(int button);
bool		is_translation(int button);

//*SELECT_MODE
void		select_mode(int button, t_img *img);

//*TRANSFORMS
void		translate(t_img *img, int button);
void		rotate(t_img *img, int button);

//*RESET
void		reset_img(t_img *img);

//*ROTATE_CAM
void		rotate_cam(t_img *img, int button);

//*ROTATE_OBJ
void		rotate_obj(t_obj *obj, int button);

//*TRANSLATE_CAM
void		translate_cam(t_img *img, int button);

//*TRANSLATE_POINT
void		translate_point(t_vec3 *point, int button);

//*RESIZE_OBJ
void		resize_obj(t_img *img, int button, t_obj *obj);

#endif
