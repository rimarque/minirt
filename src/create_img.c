/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:18:36 by rita              #+#    #+#             */
/*   Updated: 2023/12/27 01:15:49 by rita             ###   ########.fr       */
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
void	square(int x, int y, t_img img)
{
	int i = 0;
	int l = 100;
	while (i < l)
	{
		put_pixel_img(img, x, y, encode_rgb(0, 0, 255));
		put_pixel_img(img, x, y - l, encode_rgb(0, 0, 255));
		x++;
		i++;
	}
	i = 0;
	while (i < l)
	{
		put_pixel_img(img, x, y, encode_rgb(0, 0, 255));
		put_pixel_img(img, x - l, y, encode_rgb(0, 0, 255));
		y--;
		i++;
	}
}

//!My put pixel nao aceita coordenadas negativas!!
void	draw_test(t_img img)
{
	int i = 0;
	int x = WIN_W / 2;
	int y = WIN_H - 100;
	//put_pixel_img(img, -1, 0, encode_rgb(0, 125, 125));
	while (i < WIN_H - 200)
	{
		put_pixel_img(img, x, y, encode_rgb(255, 0, 0));
		y--;
		i++;
	}
	i = 0;
	y = WIN_H - 100;
	x = x - 200;
	square(x, y, img);
	square(x + 300, y, img);

}
