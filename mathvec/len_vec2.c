/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_vec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:46:07 by rita              #+#    #+#             */
/*   Updated: 2023/12/29 11:44:43 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mathvec.h"

float vec2_lensqr(t_vec2 a)
{
    return(vec2_dot(a, a));
}

float vec2_lenght(t_vec2 a)
{
    return(sqrt(vec2_lensqr(a)));
}