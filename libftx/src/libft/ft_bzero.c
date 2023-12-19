/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:41:40 by dinoguei          #+#    #+#             */
/*   Updated: 2023/12/19 19:03:18 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
int	main(void)
{
	char	teste[] = "Mai Sakurajima";
	char	testecpy[] = "Mai Sakurajima";

	printf("Original:\n");
	printf("%s\n", teste);
	printf("By my function:\n");
	ft_bzero(teste, 4);
	printf("%s\n", teste);
	printf("By the original:\n");
	bzero(testecpy, 4);
	printf("%s\n", testecpy);
}
*/
