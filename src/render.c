/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:18:36 by rita              #+#    #+#             */
/*   Updated: 2024/02/05 12:50:24 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
    return (red << 16 | green << 8 | blue);
}

//x e o y vao ter um range de 2, variam entre -1 e 1
static inline int	pixel_color(int i, int j, t_scene sc)
{
	t_ray ray;
	t_vec2 pixel;
	float f;
	t_inter it;

	j = WIN_H - j - 1;
	pixel.x = ((float)i / (WIN_W - 1)) * 2 - 1;
	pixel.y = ((float)j / (WIN_H - 1)) * 2 - 1;
	ray.d = get_dir(pixel, *sc.cam);
	ray.o = sc.cam->axis.o;
	it = intersect(ray, sc.obj, sc.n_obj);
	if(!it.inter)
		return(encode_rgb(0, 0, 0));
	else
	{
		f = compute_light(&sc, &it);
		//f = 1;
		return(encode_rgb(sc.obj[it.i].c.r * f, 
				sc.obj[it.i].c.g * f, sc.obj[it.i].c.b * f));
	}
}

void render(t_img img, t_scene sc)
{
	//ft_print_scene(&sc);
	/* t_ray ray;
	
	ray.o = sc.cam->axis.o;
	inter_cy(ray, sc.obj[0]); */
	BEGIN_IMAGE_LOOP(img)
	put_pixel_img(img, i, j, pixel_color(i, j, sc));
	END_IMAGE_LOOP
}
