/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:54:05 by rita              #+#    #+#             */
/*   Updated: 2024/01/21 14:48:52 by bde-sous         ###   ########.fr       */
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

typedef struct s_cam
{
	t_vec3	view_point;
	t_vec3	normal; // range  -1, 1
	float	fov_x; // Range 0-180
}t_cam;

typedef struct s_amb
{
	float	ratio;
	t_rgb	color;
}t_amb;


typedef struct s_light
{
	t_vec3 point;
	float ratio;
}t_light;

typedef struct s_obj
{
	int		type;
	t_vec3	point;
	t_vec3	normal; // range -1, 1
	t_rgb	color;
	float	d;
	float	h;
}t_obj;

typedef struct s_obj_list
{
	char 				*obj;
	struct s_obj_list	*next;
}t_obj_list;

typedef struct s_scene
{
	t_amb		*amb;
	t_cam		*cam;
	t_light		*light;
	t_obj		*obj;
	t_obj_list	*temp;
}t_scene;


#endif
