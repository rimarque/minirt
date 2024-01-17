/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:58:05 by rita              #+#    #+#             */
/*   Updated: 2024/01/17 14:18:45 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void	define_sc(t_scene *sc)
{
    sc->obj = malloc(sizeof(t_obj) * 2);
    sc->cam = malloc(sizeof(t_cam));
    sc->obj[0].type = PL;
	set_coord(&sc->obj[0].point, 0, -1, 0);
	set_coord(&sc->obj[0].normal, 0, 1, 0);
    set_color(sc->obj[0].c, 255, 0, 255);
    sc->obj[1].type = SP;
	set_coord(&sc->obj[1].point, 0, 0, 30);
	sc->obj[1].d = 3;
    set_color(sc->obj[0].c, 0, 0, 255);
    set_coord(&sc->cam->o, 0, 0, 0);
	set_coord(&sc->cam->view, 0, 0, 1); //!condicao para se o view for (0,0,0)
	sc->cam->aspect = (float)WIN_H/WIN_W;
	sc->cam->fov_x = 1.2;
	sc->cam->axis = get_axis(sc->cam->view, sc->cam->o);
}

int main(int argc, char **argv)
{
    t_win   minirita;
    t_img   img;
    t_scene  sc;

    if (argc != 2 || ft_strcmp(argv[1] + ft_strclen(argv[1], '.'), ".rt"))
	{
		printf("minirt: INSERT <file.rt>\n");
		return (1);
	}
    //sc = parser();
	define_sc(&sc);
    minirita = new_program(argv[1]);
    img = new_img(&minirita);
    render(img, sc);
    //draw_test(img);
    mlx_put_image_to_window(minirita.mlx_ptr, minirita.win_ptr, img.ptr, 0, 0); 
    mlx_hook(minirita.win_ptr, 17, 0L, &close_window, (void *)&img);
    mlx_key_hook(minirita.win_ptr, handle_key_event, &img);
    mlx_loop(minirita.mlx_ptr);
}
