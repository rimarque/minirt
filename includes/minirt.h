/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:54:05 by rita              #+#    #+#             */
/*   Updated: 2024/01/16 13:10:57 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <errno.h>
# include <math.h>
# include <stdint.h>
# include "../mathvec/includes/mathvec.h"
# include "../mlx/mlx.h"
# include "../libftrm/includes/libft.h"

# define ESC 65307
# define PI 3.1415
# define ANG_ROT PI/8
# define WIN_W 1280
# define WIN_H 700
#define BEGIN_IMAGE_LOOP(img) int i =0; int j=0; while(i<WIN_W/4){j=0;while(j<WIN_H/4){
#define END_IMAGE_LOOP j++;}i++;}

typedef struct s_inter
{
	bool inter;
	t_vec3 point;
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

typedef	struct s_rgb
{
	uint8_t	r;
	uint8_t g;
	uint8_t b;	
}t_rgb;

typedef struct s_amb
{
	float	ratio;
	t_rgb	color;
}t_amb;

//*aqui basta ter o axis, o fov_x e o aspect;
typedef struct s_cam
{
	t_vec3	o;
	t_vec3	view; //precisamos de 3 vetores
	float	fov_x; //!tanfov_y = tanfov_x * aspect
	float	aspect; //*H / W
	t_mt	axis;
}t_cam;

typedef struct s_light
{
	t_vec3 point;
	float ratio;
}t_light;

typedef struct s_sp
{
	t_vec3	center;
	float	d;
	t_rgb	color;
}t_sp;


typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
	t_rgb	color;
}t_plane;

typedef struct s_cy
{
	t_vec3	center;
	t_vec3	normal;
	float	d;
	float	h;
	t_rgb	color;
}t_cy;

typedef struct s_scene
{
	t_amb		*amb;
	t_cam		*cam;
	t_light		*light;
	t_sp		*sp;
	t_plane		*pl;
	t_cy		*cy;
}t_scene;

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

#endif