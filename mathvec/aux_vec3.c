/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:16:41 by rita              #+#    #+#             */
/*   Updated: 2024/02/12 13:22:33 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mathvec.h"

void	set_coord(t_vec3 *vec, float a, float b, float c)
{
	vec->x = a;
	vec->y = b;
	vec->z = c;
}

void	print_vec(char *id, t_vec3 vec)
{
	printf("%s x: %f; y: %f; z: %f;\n", id, vec.x, vec.y, vec.z);
}
