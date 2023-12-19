/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:19:26 by dinoguei          #+#    #+#             */
/*   Updated: 2023/12/19 19:03:18 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	char a;
	int	stdin;
	int	stdout;
	int	stderr;

	a = 'x';
	stdin = 0;
	stdout = 1;
	stderr = 2;
	printf("With the standard input:\n");
	ft_putchar_fd(a, stdin);
	printf("\n");
	printf("With the standard output:\n");
	ft_putchar_fd(a, stdout);
	printf("\n");
	printf("With the standard error:\n");
	ft_putchar_fd(a, stderr);
	printf("\n");
}
*/
