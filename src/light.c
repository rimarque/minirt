/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:12:17 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/01 22:03:06 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float   compute_light(t_scene *scene, t_vec3 p, t_vec3 temp)
{
    float i;
    t_vec3 n;
    float dot;

    i = scene->amb->ratio;
    n = vec3_normalized(vec3_sub(p, temp)); //verificar ordem dos params
    dot = vec3_dot(n, scene->light->point);
    if (dot > 0)
        i += scene->light->ratio * dot / (vec3_lenght(n) * vec3_lenght(scene->light->point));
    return(i);
}
