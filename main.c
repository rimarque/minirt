/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:58:05 by rita              #+#    #+#             */
/*   Updated: 2024/02/09 11:49:17 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

//todo: guardar coisas que se repetem nos calculos:
//c = vec3_dot(co, co) - sp.r_sq;
int main(int argc, char **argv)
{
    t_win   win;
    t_img   img;
    t_scene  scene;
    t_scene  original_scene;

    if (argc != 2 || !ft_strrchr(argv[1], '.') || ft_strcmp(ft_strrchr(argv[1], '.'), ".rt"))
	{
		printf("minirt: INSERT <file.rt>\n");
		return (1);
	}
    init_scene(&original_scene);
    init_scene(&scene);
    if(map_validate(argv[1], &scene) == 0)
    {
        ft_free_scene(&scene);
        return(1);
    }
    //ft_print_scene(&scene);
    init_program(&img, &scene, &original_scene, &win);
/*     img.scene->obj[0].h = 666;
    ft_print_scene(img.scene);
    ft_print_scene(img.original_scene); */
    render(img, scene);
    mlx_put_image_to_window(img.win->mlx_ptr, img.win->win_ptr, img.ptr, 0, 0); 
    mlx_hook(img.win->win_ptr, 17, 0L, &close_window, (void *)&img);
    mlx_key_hook(img.win->win_ptr, handle_key_event, &img);
    mlx_loop(img.win->mlx_ptr);
}
