/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:11:40 by dinoguei          #+#    #+#             */
/*   Updated: 2023/12/19 19:03:18 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
int	main(void)
{
	printf("Original:\n");
	printf("%c\n%c\n%c\n", 'a', 'A', '9');
	printf("By my function:\n");
	printf("%c\n%c\n%c\n", ft_tolower('a'), ft_tolower('A'), ft_tolower('9'));
	printf("By the original:\n");
	printf("%c\n%c\n%c\n", tolower('a'), tolower('A'), tolower('9'));
}
*/
