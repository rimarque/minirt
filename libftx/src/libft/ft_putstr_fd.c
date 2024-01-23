/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:27:12 by dinoguei          #+#    #+#             */
/*   Updated: 2023/12/19 19:03:18 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	n;

	if (!s)
		return ;
	n = ft_strlen((char *)s);
	write(fd, &*s, n);
}
/*
int	main(void)
{
	char teste[] = "Karin Mochizuki";
	int	stdin;
	int	stdout;
	int	stderr;

	stdin = 0;
	stdout = 1;
	stderr = 2;
	printf("With the standard input:\n");
	ft_putstr_fd(teste, stdin);
	printf("\n");
	printf("With the standard output:\n");
	ft_putstr_fd(teste, stdout);
	printf("\n");
	printf("With the standard error:\n");
	ft_putstr_fd(teste, stderr);
	printf("\n");
}
*/