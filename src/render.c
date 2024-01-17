/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:18:36 by rita              #+#    #+#             */
/*   Updated: 2024/01/17 14:16:52 by rimarque         ###   ########.fr       */
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

t_inter	inter_pl(t_ray ray, t_obj pl, t_inter prev_it)
{
	t_inter it;
	float	t;

	//print_vec("ray_o:", ray.o);
	//print_vec("ray_d:", ray.d);
	t = vec3_dot(vec3_sub(pl.point, ray.o), pl.normal) 
	/ vec3_dot(vec3_normalized(ray.d), pl.normal);
	//printf("t: %f\n", t);
	if(t < 0 || (prev_it.inter && prev_it.t < t)){
		it.inter = false;
		return(it);
	}
	it.point = vec3_add(ray.o, vec3_scale(ray.d, t));
	it.inter = true;
	return(it);
}

t_inter	inter_sp(t_ray ray, t_obj sp, t_inter prev_it)
{
	t_inter	it;
	float	t1;
	float	t2;
	t_vec3	point1;
	t_vec3	point2;
	t_vec3	co;
	float	a;
	float	b;
	float	c;
	float	in_sqr;

	//print_vec("ray_o:", ray.o);
	//print_vec("ray_d:", ray.d);
	co = vec3_sub(ray.o, sp.point);
	a = vec3_dot(ray.d, ray.d);
	b = 2 * vec3_dot(ray.d, co);
	c = vec3_dot(co, co) - sp.d * sp.d;
	in_sqr = b * b - 4 * a * c;
	if (in_sqr < 0)
	{
		it.inter = false;
		return(it);
	}
	t1 = (-b + sqrtf(in_sqr)) / 2 * a;
	t2 = (-b - sqrtf(in_sqr)) / 2 * a;
	if(t1 < 0 && t2 < 0)
	{
		it.inter = false;
		return(it);
	}
	it.inter = true;
	if (in_sqr == 0){
		if(prev_it.inter && prev_it.t < it.t)
			return(it.inter = false, it);
		it.t = t1;
		it.point = vec3_add(ray.o, vec3_scale(ray.d, t1));
		return(it);
	}
	point1 = vec3_add(ray.o, vec3_scale(ray.d, t1));
	point2 = vec3_add(ray.o, vec3_scale(ray.d, t2));
	if(t1 > 0 && t2 > 0)
	{
		if(t1 < t2)
		{
			it.t = t1;
			it.point = point1;
		}
		else
		{
			it.t = t2;
			it.point = point2;
		}
	}
	else if(t1 > 0)
	{
		it.t = t1;
		it.point = point1;
	}
	else if(t2 > 0){
		it.t = t2;
		it.point = point2;
	}
	if(prev_it.inter && prev_it.t < it.t)
		return(it.inter = false, it);
	return(it);
}

t_inter intersect(t_ray ray, t_obj *obj, int n)
{
	int i;
	t_inter prev_it;
	t_inter it;

	it.inter = false;
	i = 0;
	while(i < n)
	{
		if(obj[i].type == PL)
		{
			it = inter_pl(ray, obj[i], prev_it);
			it.i = i;
		}
		if(obj[i].type == SP)
		{
			it = inter_sp(ray, obj[i], prev_it);
			it.i = i;
		}
		//if(obj[i].type == CY)
		//	inter_cy();
		if (it.inter)
			prev_it = it;
		i++;
	}
	return(it);
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
	//return(encode_rgb(255 *ray.d.x * 10, 255 *ray.d.y * 10, 255 *ray.d.z * 10));
	if(!it.inter)
		return(encode_rgb(0, 0, 0));
	else
	{
		if(sc.obj[it.i].type == SP)
			f = (vec3_lenght(vec3_sub(sc.cam->o, sc.obj[it.i].point)) - it.t)/sc.obj[it.i].d;
		else
			f = 1;
		return(encode_rgb(sc.obj[it.i].c->r * f, 
				sc.obj[it.i].c->g * f, sc.obj[it.i].c->b * f));
	}
}

void render(t_img img, t_scene sc)
{
	BEGIN_IMAGE_LOOP(img)
	put_pixel_img(img, i, j, pixel_color(i, j, sc));
	END_IMAGE_LOOP
}
