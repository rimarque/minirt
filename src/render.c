/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:18:36 by rita              #+#    #+#             */
/*   Updated: 2024/01/16 19:16:43 by rimarque         ###   ########.fr       */
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

t_inter	inter_pl(t_ray ray, t_plane pl)
{
	t_inter inter;
	
	print_vec("ray_o:", ray.o);
	print_vec("ray_d:", ray.d);
	float t = vec3_dot(vec3_sub(pl.point, ray.o), pl.normal) / vec3_dot(vec3_normalized(ray.d), pl.normal);
	printf("t: %f\n", t);
	if(t < 0){
		inter.inter = false;
		return(inter);
	}
	inter.point = vec3_add(ray.o, vec3_scale(ray.d, t));
	inter.inter = true;
	return(inter);
}

t_inter	inter_sp(t_ray ray, t_sp sp)
{
	t_inter inter;
	float t1;
	float t2;
	t_vec3 point1;
	t_vec3 point2;
	
	//print_vec("ray_o:", ray.o);
	//print_vec("ray_d:", ray.d);
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
	if(t1 < 0 && t2 < 0)
	{
		inter.inter = false;
		return(inter);
	}
	inter.inter = true;
	if (in_sqr == 0){
		inter.point = vec3_add(ray.o, vec3_scale(ray.d, t1));
		return(inter);
	}
	point1 = vec3_add(ray.o, vec3_scale(ray.d, t1));
	point2 = vec3_add(ray.o, vec3_scale(ray.d, t2));
	if(t1 > 0 && t2 > 0)
	{
		if(t1 < t2){
			inter.t = t1;
			inter.point = point1;
		}
		else{
			inter.t = t2;
			inter.point = point2;
		}
	}
	else if(t1 > 0){
		inter.t = t1;
		inter.point = point1;
	}
	else if(t2 > 0){
		inter.t = t2;
		inter.point = point2;
	}
	return(inter);
}

//x e o y vao ter um range de 2, variam entre -1 e 1
static inline int	pixel_color(int i, int j, t_scene sc)
{
	t_ray ray;
	t_vec2 pixel;
	float f;

	j = WIN_H - j - 1;
	pixel.x = ((float)i / (WIN_W - 1)) * 2 - 1;
	pixel.y = ((float)j / (WIN_H - 1)) * 2 - 1;
	ray.d = get_dir(pixel, *sc.cam);
	ray.o = sc.cam->axis.o;
	//t_inter inter = inter_pl(ray, *sc.pl);
	t_inter inter = inter_sp(ray, *sc.sp);
	//return(encode_rgb(255 *ray.d.x * 10, 255 *ray.d.y * 10, 255 *ray.d.z * 10));
	if(!inter.inter)
		return(encode_rgb(0, 0, 0));
	else{
		f = (vec3_lenght(vec3_sub(sc.cam->o, sc.sp->center)) - inter.t)/sc.sp->d;
		return(encode_rgb(0, 0 , f*255));
	}
}

void render(t_img img, t_scene sc)
{
	BEGIN_IMAGE_LOOP(img)
	put_pixel_img(img, i, j, pixel_color(i, j, sc));
	END_IMAGE_LOOP
}
