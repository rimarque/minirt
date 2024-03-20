/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:38:45 by rita              #+#    #+#             */
/*   Updated: 2024/02/12 13:26:52 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mathvec.h"

//Considere-se uma matriz formada por três vetores, 
//Cada coluna da matriz é um vetor (x, y e z)

//Esta funçao retorna a matriz de rotaçao pelo eixo x
//de acordo com o angulo teta
t_matrix	get_rotmatrix_x(float teta)
{
	t_matrix	matrix;

	set_coord(&matrix.x, 1, 0, 0);
	set_coord(&matrix.y, 0, cosf(teta), sinf(teta));
	set_coord(&matrix.z, 0, -1 * sinf(teta), cosf(teta));
	return (matrix);
}

//Esta funçao retorna a matriz de rotaçao pelo eixo y,
//de acordo com o angulo teta
t_matrix	get_rotmatrix_y(float teta)
{
	t_matrix	matrix;

	set_coord(&matrix.x, cosf(teta), 0, -1 * sinf(teta));
	set_coord(&matrix.y, 0, 1, 0);
	set_coord(&matrix.z, sinf(teta), 0, cosf(teta));
	return (matrix);
}

//Esta funçao retorna a matriz de rotaçao pelo eixo z,
//de acordo com o angulo teta
t_matrix	get_rotmatrix_z(float teta)
{
	t_matrix	matrix;

	set_coord(&matrix.x, cosf(teta), sinf(teta), 0);
	set_coord(&matrix.y, -1 * sinf(teta), cosf(teta), 0);
	set_coord(&matrix.z, 0, 0, 1);
	return (matrix);
}

//Multiplicar matriz por um vetor
t_vec3	vec3_mltmatrix(t_matrix mt, t_vec3 vec)
{
	t_vec3	result;

	result.x = vec.x * mt.x.x + vec.y * mt.y.x + vec.z * mt.z.x;
	result.y = vec.x * mt.x.y + vec.y * mt.y.y + vec.z * mt.z.y;
	result.z = vec.x * mt.x.z + vec.y * mt.y.z + vec.z * mt.z.z;
	return (result);
}

//Multiplicar matriz por outra matriz
t_matrix	matrix_mltmatrix(t_matrix mt1, t_matrix mt2)
{
	t_matrix	result;

	result.x = vec3_mltmatrix(mt1, mt2.x);
	result.y = vec3_mltmatrix(mt1, mt2.y);
	result.z = vec3_mltmatrix(mt1, mt2.z);
	return (result);
}
