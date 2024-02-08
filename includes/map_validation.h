/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:54:05 by rita              #+#    #+#             */
/*   Updated: 2024/02/08 19:59:58 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H

# include <errno.h>
# include <math.h>
# include <stdint.h>
# include "../mathvec/includes/mathvec.h"
# include "../libftrm/includes/libft.h"

typedef	struct s_rgb
{
	uint8_t	r;
	uint8_t g;
	uint8_t b;	
}t_rgb;

typedef struct s_amb
{
	float	ratio;
	t_rgb	c;
}t_amb;

//!invalid map, if normal = (0, 0, 0)
typedef struct s_cam
{
	t_vec3	view_point;
	t_vec3	normal;
	float	fov_x;
	float	aspect; //*H / W
	t_matrix	axis;
}t_cam;

typedef struct s_light
{
	t_vec3 point;
	float ratio;
}t_light;

//color nao precisa de ser um ponteiro
typedef struct s_obj
{
	int		type;
	t_vec3	point;
	t_vec3	vector; // range -1, 1
	t_vec3	vec_inver;
	t_vec3	base1_c;
	t_vec3	base2_c;
	t_rgb	c;
	float	h;
	float	r;
	float	r_sq;
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
	int			n_obj;
}t_scene;

int	ft_freedoublepointer(char **dptr);
int float_in_range(float value, float min, float max);
int	ft_ischar(const char *str, uint8_t *val);
int	ft_isfloat(const char *str, float *val, int normalized);
int parse_color(char *str, t_rgb *rgb);
int parse_vec3(char *str, t_vec3 *vec, int normalized);
int validate_A(char **line, t_scene *scene);
int validate_C(char **line, t_scene *scene);
int validate_L(char **line, t_scene *scene);
int validate_sp(char **line, t_obj *obj);
int validate_cy(char **line, t_obj *obj);
int validate_pl(char **line, t_obj *obj);
int validate_line(char *line, t_scene *scene);
int addNode(char *str, t_obj_list **head);
int	ft_stack_length(t_obj_list *stack);
void ft_initobj(t_obj *obj);
int validate_obj(char *line, t_obj *obj);
int list_to_obj(t_scene *scene);
void init_scene(t_scene *scene);
int ft_put_err();
int final_check(t_scene *scene);
int open_map(char *str);
int map_validate(char *file, t_scene *scene);
int	freestack(t_obj_list *stack);
void ft_free_objarray(t_obj *obj, int len);
void ft_free_scene(t_scene *scene);
void ft_print_vec(t_vec3 *vec);
void ft_print_color(t_rgb *rgb);
void ft_print_amb(t_amb *amb);
void ft_print_cam(t_cam *cam);
void ft_print_light(t_light *light);
void ft_print_obj(t_obj *obj, int num);
void ft_print_scene(t_scene *scene);


#endif
