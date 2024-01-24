/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:26:10 by rita              #+#    #+#             */
/*   Updated: 2023/12/29 11:59:43 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mathvec.h"

t_vec3 vec3_add(t_vec3 a, t_vec3 b)
{
    t_vec3 result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return(result);
}

t_vec3 vec3_sub(t_vec3 a, t_vec3 b)
{
    t_vec3 result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return(result);
}

t_vec3 vec3_normalized(t_vec3 a)
{
    t_vec3  result;
    float   len;
    
    len = vec3_lenght(a);
    result.x = a.x / len;
    result.y = a.y / len;
    result.z = a.z / len;
    return(result);
}