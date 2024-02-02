/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:58:05 by rita              #+#    #+#             */
/*   Updated: 2024/01/31 13:57:56 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

//*guardei o raio e o raio ao quadrado (eliminei o d);
//todo: guardar coisas que se repetem nos calculos:
//c = vec3_dot(co, co) - sp.r_sq;
//cy.vector = vec3_scale(cy.vector, -1);

int main(int argc, char **argv)
{
    t_win   minirita;
    t_img   img;
    t_scene  sc;

    if (argc != 2 || !ft_strrchr(argv[1], '.') || ft_strcmp(ft_strrchr(argv[1], '.'), ".rt"))
	{
		printf("minirt: INSERT <file.rt>\n");
		return (1);
	}
    init_scene(&sc);
    if(map_validate(argv[1], &sc) == 0)
    {
        ft_free_scene(&sc);
        return(1);
    }
    //ft_print_scene(&scene);
    minirita = new_program(argv[1]);
    img = new_img(&minirita);
    render(img, sc);
    mlx_put_image_to_window(minirita.mlx_ptr, minirita.win_ptr, img.ptr, 0, 0); 
    mlx_hook(minirita.win_ptr, 17, 0L, &close_window, (void *)&img);
    mlx_key_hook(minirita.win_ptr, handle_key_event, &img);
    mlx_loop(minirita.mlx_ptr);
}
