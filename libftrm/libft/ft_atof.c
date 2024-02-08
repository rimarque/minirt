/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:59:22 by bde-sous          #+#    #+#             */
/*   Updated: 2024/01/07 17:58:26 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double	ft_atof(const char *str)
{
	double	inteiro;
	double	restante;
	int		len;
	char	sign;

	inteiro = 0;
	restante = 0;
	len = 0;
	while (*str == ' ' || ((*str >= '\t') && (*str <= '\r')))
		str++;
	sign = *str;
	inteiro = (double)ft_atoll(str);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	restante = (double)ft_atoll(str);
	len = ft_strlen(str);
	while (len--)
		restante /= 10;
	if ((inteiro < 0) || ((inteiro == 0) && (sign == '-')))
		return (inteiro + -restante);
	else
		return (inteiro + restante);
}
