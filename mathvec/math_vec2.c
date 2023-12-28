/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:31:22 by rita              #+#    #+#             */
/*   Updated: 2023/12/28 17:25:22 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mathvec.h"

t_vec2 vec2_add(t_vec2 a, t_vec2 b)
{
    t_vec2 result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return(result);
}

t_vec2 vec2_sub(t_vec2 a, t_vec2 b)
{
    t_vec2 result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return(result);
}

t_vec2 vec2_normal(t_vec2 a)
{
    t_vec2  result;
    float   len;
    
    len = vec2_lenght(a);
    result.x = a.x / len;
    result.y = a.y / len;
    return(result);
}