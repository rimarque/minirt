/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:38:45 by rita              #+#    #+#             */
/*   Updated: 2024/01/16 13:19:16 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mathvec.h"
//multiplicar matriz por um vetor
//neste caso a matriz e formada por quatro vetores, cada coluna da matriz e um vetor (x, y e z do axis e o (a origem do axis))
t_vec3  vec3_mtpmt(t_vec3 vec, t_mt mt)
{
    t_vec3 result;

    result.x = vec.x * mt.x.x + vec.y * mt.y.x + vec.z * mt.z.x + mt.o.x;
    result.y = vec.x * mt.x.y + vec.y * mt.y.y + vec.z * mt.z.y + mt.o.y;
    result.z = vec.x * mt.x.z + vec.y * mt.y.z + vec.z * mt.z.z + mt.o.z;
    //result = vec3_add(vec3_add(vec3_add(vec3_add(vec, mt.o), vec3_scale(mt.x, vec.x)), vec3_scale(mt.y, vec.y)), vec3_scale(mt.z, vec.z));
    return(result);
}

//multiplica um vetor por uma matriz (da forma que o sratch a pixel ensina)
//neste caso a matriz e formada por 3 vetores:
//x([0][0], [0][1], [0][2]), y([1][0], [1][1], [1][2]) e z([2][0], [2][1], [2][2]) que sao as linhas da matriz
/*t_vec3  vec3_tm(t_vec3 a, float **m3)
{
    t_vec3 result;

    result.x = a.x * m3[0][0] + a.y * m3[1][0] + a.z * m3[2][0];
    result.y = a.x * m3[0][1] + a.y * m3[1][1] + a.z * m3[2][1];
    result.z = a.x * m3[0][2] + a.y * m3[1][2] + a.z * m3[2][2];
    return(result);
}*/
//rodar pelo eixo dos y (recebe o vetor)
//rodar pelo eixo dos x (recebe o vetor)
//rodar pelo eixo do z (recebe o vetor)