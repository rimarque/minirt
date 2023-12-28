/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_vec2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:49:31 by rita              #+#    #+#             */
/*   Updated: 2023/12/28 17:25:27 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mathvec.h"

float vec2_dot(t_vec2 a, t_vec2 b)
{
    return(a.x * b.x + a.y * b.y);
}

t_vec2 vec2_scale(t_vec2 a, float b)
{
    t_vec2 result;

    result.x = a.x * b;
    result.y = a.y * b;
    return(result);
}