/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:18:36 by rita              #+#    #+#             */
/*   Updated: 2024/01/15 22:26:03 by rita             ###   ########.fr       */
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
void print_vec(t_vec3 vec)
{
	printf("x: %f; y: %f; z: %f;\n", vec.x, vec.y, vec.z);
}

t_inter	inter_pl(t_ray ray, t_plane pl)
{
	t_inter inter;
	
	/* printf("cima: %f\nbaixo: %f\n", vec3_dot(vec3_sub(pl.point, ray.o), pl.normal), vec3_dot(ray.d, pl.normal));
	printf("ponto do plano: ");
	print_vec(pl.point);
	printf("normal do plano: ");
	print_vec(pl.normal);
	printf("ray or: ");
	print_vec(ray.o);
	printf("ray d ");
	print_vec(ray.d); */
	float t = vec3_dot(vec3_sub(pl.point, ray.o), pl.normal) / vec3_dot(vec3_normalized(ray.d), pl.normal);
	if(t < 0){
		inter.inter = false;
		return(inter);
	}
	//printf("AAAAAAAAAAAAAAAAA\n");42
	inter.point = vec3_add(ray.o, vec3_scale(ray.d, t));
	//printf("point.x: %f\npoint.y: %f\npoint.z: %f\nvalor de t: %f\n", inter.point.x, inter.point.y, inter.point.z, t);
	inter.inter = true;
	return(inter);
}

t_inter	inter_sp(t_ray ray, t_sp sp)
{
	t_inter inter;
	float t1;
	float t2;
	
	t_vec3 co = vec3_sub(ray.o, sp.center);
	float a = vec3_dot(ray.d, ray.d);
	float b = 2 * vec3_dot(ray.d, co);
	float c = vec3_dot(co, co) - sp.d * sp.d;
	float in_sqr = b * b - 4 * a * c;
	if (in_sqr < 0)
	{
		inter.inter = false;
		return(inter);
	}
	t1 = (-b + sqrtf(in_sqr)) / 2 * a;
	t2 = (-b - sqrtf(in_sqr)) / 2 * a;
	inter.inter = true;
	if (in_sqr == 0){
		inter.point = vec3_add(ray.o, vec3_scale(ray.d, t1));
		return(inter);
	}
	t_vec3 point1 = vec3_add(ray.o, vec3_scale(ray.d, t1));
	t_vec3 point2 = vec3_add(ray.o, vec3_scale(ray.d, t2));
	if(vec3_lensqr(vec3_sub(point1, ray.o)) < vec3_lensqr(vec3_sub(point2, ray.o)))
		inter.point = vec3_add(ray.o, vec3_scale(ray.d, t1));
	else
		inter.point = vec3_add(ray.o, vec3_scale(ray.d, t2));
	return(inter);
}

//x e o y vao ter um range de 2
static inline int	pixel_color(int i, int j, t_scene sc)
{
	t_ray ray;
	t_vec2 pixel;

	j = WIN_H - j - 1;
	pixel.x = ((float)i / (WIN_W - 1)) * 2 - 1 ; //varia entre -1 e 1
	pixel.y = ((float)j / (WIN_H - 1)) * 2 - 1;
	ray.d = get_dir(pixel, *sc.cam);
	ray.o = sc.cam->axis.o;
	//t_inter inter = inter_pl(ray, pl);
	t_inter inter = inter_sp(ray, *sc.sp);
	//return(encode_rgb(255 *ray.d.x * 10, 255 *ray.d.y * 10, 255 *ray.d.z * 10));
	if(!inter.inter)
		return(encode_rgb(0, 0, 0));
	else{
		//return(encode_rgb(26, 102, 46));
		//printf("z: %f\n", inter.point.z);
		//inter.point.z= fabs(inter.point.z);
		//inter.point.z = ((fabs(sp.center.z) - inter.point.z) / 3) * 0.7;
		//inter.point.z = vec3_lenght(vec3_sub(inter.point, sp.center)) / 3;
		//inter.point.z = (vec3_lensqr(vec3_sub(inter.point, ray.o)) / vec3_lensqr(vec3_sub(sp.center, ray.o)));
		return(encode_rgb(255, 0 , 255));
	}
	//pixel.y *= (float)WIN_H/WIN_W; //a escala de pixel.y fica igual a de pixel.x
	/*if(in_circle(pixel)){
		//float f = 1.0 - sqrt(powf(pixel.x, 2) + powf(pixel.y, 2)); //1 - comprimento do vetor -> vai dar um fator de escurecimento maior
		float f = 1.0 - 2*vec2_lensqr(pixel); //1 - quadrado do comprimento o vetor*q
													//-> fator para multiplicar pelo rgb, 
													//assim, quanto maior o comprimento, menor o rgb
		return(encode_rgb(255 * f, 255 * f, 255 * f)); //quanto maior o comprimento do vetor, menor o uint
														//quanto maior a distancia ao centro do circulo, mais escuro
	}
	pixel.x = fabs(pixel.x);
	pixel.y = fabs(pixel.y);
	return(encode_rgb(255 * pixel.x, 255 * pixel.y, 0)); //a cor varia entre 0 e 255*/
}

void	define_sc(t_scene *sc)
{
	t_cam cam;
	
	set_coords(sc->pl->point, 0, -1, 0);
	set_coords(sc->pl->normal, 5, 3, 1);
	set_coords(sc->pl->point, 0, -1, 0);
	set_coords(sc->sp->center, 0, 0, -30);
	sc->sp->d = 3;
	sc->cam->aspect = (float)WIN_H/WIN_W;
	sc->cam->fov_x = 1.0;
	set_coords(sc->cam->o, 5, 2, 1);
	set_coords(sc->cam->view, 4, 2, 1);
	sc->cam->axis = get_axis(sc->cam->view, sc->cam->o);
}

void render(t_img img, t_scene sc)
{
	(void)sc;
	t_scene test;
	define_sc(&test);
	BEGIN_IMAGE_LOOP(img)
	put_pixel_img(img, i, j, pixel_color(i, j, test));
	END_IMAGE_LOOP
}
