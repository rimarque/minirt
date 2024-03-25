/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-18 19:36:01 by bde-sous          #+#    #+#             */
/*   Updated: 2024-03-18 19:36:01 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ft_print_obj(t_obj *obj, int num)
{
	int		i;
	char	*tipos[3];

	tipos[0] = "PL";
	tipos[1] = "SP";
	tipos[2] = "CY";
	printf("---OBJECTS---\n\n");
	i = -1;
	while (i++ < num -1)
	{
		printf("Obj %d %s\n", i, tipos[obj[i].type]);
		ft_print_color(&obj[i].color);
		printf("point\n");
		ft_print_vec(&obj[i].point);
		printf("normalized\n");
		ft_print_vec(&obj[i].vector);
		printf("R SQ:       %f\n", obj[i].r_sqr);
		printf("H:          %f\n", obj[i].h);
		printf("\n");
	}
	printf("\n\n");
}

void	ft_print_vec(t_vec3 *vec)
{
	printf("vec:        x %f\n", vec->x);
	printf("            y %f\n", vec->y);
	printf("            z %f\n", vec->z);
}

void	ft_print_color(t_rgb *rgb)
{
	printf("RGB:        r %d\n", rgb->r);
	printf("            g %d\n", rgb->g);
	printf("            b %d\n", rgb->b);
}
