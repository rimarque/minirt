/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:59:38 by dinoguei          #+#    #+#             */
/*   Updated: 2023/12/19 19:03:18 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	int			temp;

	temp = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		temp *= 10;
		temp += *str - 48;
		str++;
	}
	return (temp * sign);
}
/*
int	main(void)
{
	char	*teste = "	  -4564x89";

	printf("%d", ft_atoi(teste));
}
*/
