/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:12:17 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/26 23:54:55 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool shadow(t_scene scene, t_inter it, t_vec3 l, float len_l)
{
    t_ray  shadow_dir;
    
    shadow_dir.o = it.point;
    shadow_dir.d = vec3_normalized(l);
    if (intersect_shadow(shadow_dir,scene, it.i, len_l)) 
            return true; 
    return false; 
}


// l    --> Light Direction
// n    --> Object Norm
// i    --> intensidade luz
float   compute_light(t_scene scene, t_inter it)
{
    float i;
    float dot;
    t_vec3 l;
    float   len_l;

    i = scene.amb->ratio;
    l = vec3_sub(scene.light->point, it.point);
    len_l =  vec3_lenght(l);
    dot = vec3_dot(it.normal, l);
    if (dot > 0 && !shadow(scene, it, l, len_l))
        i += (scene.light->ratio * dot) / (vec3_lenght(it.normal) * len_l);
    if (i > 1)
        return(1);
    return(i);
}
