/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:38:45 by rita              #+#    #+#             */
/*   Updated: 2024/01/15 23:02:33 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mathvec.h"
//multiplicar vetor por matrizes
t_vec3  vec3_mtpmt(t_vec3 vec, t_mt mt)
{
    t_vec3 result;

    result.x = vec.x * mt.x.x + vec.y * mt.y.x + vec.z * mt.z.x + mt.o.x;
    result.y = vec.x * mt.x.y + vec.y * mt.y.y + vec.z * mt.z.y + mt.o.y;
    result.z = vec.x * mt.x.z + vec.y * mt.y.z + vec.z * mt.z.z + mt.o.z;
    //result = vec3_add(vec3_add(vec3_add(vec3_add(vec, mt.o), vec3_scale(mt.x, vec.x)), vec3_scale(mt.y, vec.y)), vec3_scale(mt.z, vec.z));
    return(result);
}
//rodar pelo eixo dos y (recebe o vetor)
//rodar pelo eixo dos x (recebe o vetor)
//rodar pelo eixo do z (recebe o vetor)