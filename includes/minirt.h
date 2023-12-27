/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:54:05 by rita              #+#    #+#             */
/*   Updated: 2023/12/27 22:08:17 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <errno.h>
# include <math.h>
# include <stdint.h>
# include "../mlx/mlx.h"
# include "../libftrm/includes/libft.h"

# define ESC 65307
# define WIN_W 1280
# define WIN_H 700
# define WIN_Z 150.0 //!Para que serve?
#define BEGIN_IMAGE_LOOP(img) int i =0; int j=0; while(i<WIN_W){j=0;while(j<WIN_H){
#define END_IMAGE_LOOP j++;}i++;}

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

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}t_vec3;

typedef struct s_vec2
{
	float	x;
	float	y;
}t_vec2;

typedef struct s_amb
{
	float	ratio;
	t_rgb	color;
}t_amb;

typedef struct s_cam
{
	t_vec3	view_point;
	t_vec3	orientation_vector; //precisamos de 3 vetores
	float	tangfov_x; //!fov_y = fov_x * aspect
	float	aspect; //*W / H
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

#endif