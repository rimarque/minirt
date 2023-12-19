/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:58:34 by dinoguei          #+#    #+#             */
/*   Updated: 2023/12/19 19:03:18 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = (int *)malloc(n * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}
/*
int	main(void)
{
	char	*teste = "Hatsune Miku";
	printf("Original:\n");
	printf("%s\n", teste);
	teste = ft_calloc(13,1);
	printf("Depois do Calloc:\n");
	printf("%s\n", teste);
}
*/
