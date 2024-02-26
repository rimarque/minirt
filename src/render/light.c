/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:12:17 by bde-sous          #+#    #+#             */
/*   Updated: 2024/02/26 18:58:07 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool shadow_intersection(t_scene *scene, t_inter *it, t_vec3 l)
{
    t_ray  shadow_dir;
    
    shadow_dir.o = it->point;
    shadow_dir.d = l;
    if (intersect_shadow(shadow_dir,scene->obj,scene->n_obj, it->i)) 
            return true; 
    return false; 
}


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
    dot = vec3_dot(it->normal, l);
    if (dot > 0 && !shadow_intersection(scene, it, l))
        i += scene->light->ratio * dot / (vec3_lenght(it->normal) * vec3_lenght(l));
    if (i > 1)
        return(1);
    return(i);
}
