/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:18:36 by rita              #+#    #+#             */
/*   Updated: 2023/12/29 11:59:00 by rita             ###   ########.fr       */
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

bool	in_circle(t_vec2 pixel)
{
	float r = 0.5;
	float pow_comp = vec2_lensqr(pixel); //usar o teorema de pitagoras 
												//para calcular o comprimeto do vetor 
												//(neste caso o quadrado do comprimento do vetor, o quadrado da hipotenusa das coordenadas)
	if (pow_comp < r*r) //se o comprimento do vetor for menor que o raio do circulo, entao este pixel pertence ao circulo
		return(true);
	return(false);
}
//x e o y vao ter um range de 2
int	pixel_color(int i, int j)
{
	t_vec2 pixel;
	j = WIN_H - j - 1;
	pixel.x = ((float)i / (WIN_W - 1)) * 2 - 1 ; //varia entre -1 e 0
	pixel.y = ((float)j / (WIN_H - 1)) * 2 - 1; 
	pixel.y *= (float)WIN_H/WIN_W; //a escala de pixel.y fica igual a de pixel.x
	if(in_circle(pixel)){
		//float f = 1.0 - sqrt(powf(pixel.x, 2) + powf(pixel.y, 2)); //1 - comprimento do vetor -> vai dar um fator de escurecimento maior
		float f = 1.0 - 2*vec2_lensqr(pixel); //1 - quadrado do comprimento o vetor*q
													//-> fator para multiplicar pelo rgb, 
													//assim, quanto maior o comprimento, menor o rgb
		return(encode_rgb(255 * f, 255 * f, 255 * f)); //quanto maior o comprimento do vetor, menor o uint
														//quanto maior a distancia ao centro do circulo, mais escuro
	}
	pixel.x = fabs(pixel.x);
	pixel.y = fabs(pixel.y);
	return(encode_rgb(255 * pixel.x, 255 * pixel.y, 0)); //a cor varia entre 0 e 255
}

void render(t_img img, t_scene sc)
{
	(void)sc;
	BEGIN_IMAGE_LOOP(img)
	put_pixel_img(img, i, j, pixel_color(i, j));
	END_IMAGE_LOOP
}