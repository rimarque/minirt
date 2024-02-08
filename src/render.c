/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:18:36 by rita              #+#    #+#             */
/*   Updated: 2024/02/08 12:27:19 by rita             ###   ########.fr       */
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

/* The static inline keywords suggest that this function is defined within 
a header file and is meant to be inlined by the compiler 
for optimization purposes.
static: This keyword limits the visibility of the function to the 
translation unit in which it is defined, meaning it cannot be 
accessed from outside that unit.
inline: This keyword suggests to the compiler that it should 
try to inline this function, meaning it may insert the functions 
code directly into the calling code rather
than performing a function call. */
static inline int	pixel_color(int i, int j, t_scene sc)
{
	t_ray	ray;
	float	f;
	t_inter	it;

	ray = get_ray(i, j, sc);
	it = intersect(ray, sc.obj, sc.n_obj);
	if (!it.inter)
		return (encode_rgb(0, 0, 0));
	else
	{
		f = compute_light(&sc, &it);
		//f = 1;
		return (encode_rgb(sc.obj[it.i].c.r * f, 
				sc.obj[it.i].c.g * f, sc.obj[it.i].c.b * f));
	}
}

void render(t_img img, t_scene sc)
{
	int i;
	int j;
	
	//ft_print_scene(&sc);
	i = 0;
	j = 0; 
	while (i < WIN_W)
	{
		j=0;
		while (j < WIN_H)
		{
			put_pixel_img(img, i, j, pixel_color(i, j, sc));
			j++;
		}
		i++;
	}
}
