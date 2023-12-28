/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathvec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:10:40 by rita              #+#    #+#             */
/*   Updated: 2023/12/28 17:30:22 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHVEC_H
# define MATHVEC_H

# include "../../libftrm/includes/libft.h"
# include <math.h>

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

//*MATH_VEC3
t_vec3 vec3_add(t_vec3 a, t_vec3 b);
t_vec3 vec3_sub(t_vec3 a, t_vec3 b);
t_vec3 vec3_scale(t_vec3 a, float b);

//*LEN_VEC3
float vec3_lensqr(t_vec3 a);
float vec3_lenght(t_vec3 a);

//*PROD_VEC3
float vec3_dot(t_vec3 a, t_vec3 b);
t_vec3 vec3_cross(t_vec3 a, t_vec3 b);

//*MATH_VEC2
t_vec2 vec2_add(t_vec2 a, t_vec2 b);
t_vec2 vec2_sub(t_vec2 a, t_vec2 b);
t_vec2 vec2_scale(t_vec2 a, float b);

//*LEN_VEC2
float vec2_lensqr(t_vec2 a);
float vec2_lenght(t_vec2 a);

//*PROD_VEC2
float vec2_dot(t_vec2 a, t_vec2 b);

#endif