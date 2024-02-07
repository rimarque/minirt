/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:12:17 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/03 16:18:15 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

// l    --> Light Direction
// n    --> Object Norm
// i    --> intensidade luz

float   compute_light(t_scene *scene, t_inter *it)
{
    float i;
    float dot;
    t_vec3 l;

    i = scene->amb->ratio;
    l = vec3_sub(scene->light->point,it->point);
    //set_coord(&it->normal, 0, 1, 0);
    dot = vec3_dot(it->normal, l);
    //print_vec("normal:", it->normal);
    if (dot > 0)
        i += scene->light->ratio * dot / (vec3_lenght(it->normal) * vec3_lenght(l));
    // else
    //     i = 1;
       // i += compute_shadow(scene, it);
    return(i);
}