/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_vec3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:54:45 by rita              #+#    #+#             */
/*   Updated: 2024/01/16 11:13:57 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mathvec.h"

float	vec3_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

//Os vetores a e b formam um plano, 
//esta funcao devolve um vetor ortagonal a esse plano
t_vec3	vec3_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	cross;

	cross.x = a.y * b.z - b.y * a.z;
	cross.y = a.z * b.x - a.x * b.z;
	cross.z = a.x * b.y - a.y * b.x;
	return (cross);
}

t_vec3	vec3_scale(t_vec3 a, float b)
{
	t_vec3	result;

	result.x = a.x * b;
	result.y = a.y * b;
	result.z = a.z * b;
	return (result);
}
