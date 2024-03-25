/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-18 19:38:01 by bde-sous          #+#    #+#             */
/*   Updated: 2024-03-18 19:38:01 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	float_in_range(float value, float min, float max)
{
	return (value >= min && value <= max);
}

int	ft_ischar(const char *str, uint8_t *val)
{
	int	i;
	int	res;

	i = 0;
	if (ft_strlen(str) == 0 || ft_strlen(str) > 3)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (0);
	res = ft_atoi(str);
	if (res > 255 || res < 0)
		return (0);
	*val = res;
	return (1);
}

int	ft_isfloat(const char *str, float *val, int normalized)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	if (str[0] == '-')
		i++;
	while (((str[i] >= '0' && str[i] <= '9') || str[i] == '.') && flag < 2)
	{
		if (str[i] == '.')
			flag++;
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*val = ft_atof(str);
	if (normalized == 1 && (!float_in_range(*val, -1, 1)))
		return (0);
	if (normalized == 2 && (*val <= 0))
		return (0);
	return (1);
}

int	parse_color(char *str, t_rgb *rgb)
{
	char	**raw;
	uint8_t	irgb[3];
	int		i;

	i = 0;
	raw = ft_split(str, ',');
	while (ft_arrlen(raw) == 3 && i < 3)
	{
		if (ft_ischar(raw[i], &irgb[i]))
			i++;
		else
			return (0 & ft_freedoublepointer(raw));
	}
	if (ft_arrlen(raw) != 3)
		return (0 & ft_freedoublepointer(raw));
	*rgb = get_color(irgb[0], irgb[1], irgb[2]);
	ft_freedoublepointer(raw);
	return (1);
}

int	parse_vec3(char *str, t_vec3 *vec, int normalized)
{
	char	**raw;
	float	ivec[3];
	int		i;

	i = 0;
	raw = ft_split(str, ',');
	while (ft_arrlen(raw) == 3 && i < 3)
	{
		if (ft_isfloat(raw[i], &ivec[i], normalized))
			i++;
		else
			return (0 & ft_freedoublepointer(raw));
	}
	if (ft_arrlen(raw) != 3)
		return (ft_freedoublepointer(raw) & 0);
	ft_freedoublepointer(raw);
	vec->x = ivec[0];
	vec->y = ivec[1];
	vec->z = ivec[2];
	return (1);
}
