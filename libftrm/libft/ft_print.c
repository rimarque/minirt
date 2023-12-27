/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:33:23 by rimarque          #+#    #+#             */
/*   Updated: 2023/07/03 22:27:30 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	print_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		ft_putstr_fd(arr[i], 1);
		write(1, "\n", 1);
		i++;
	}
}

void	print_matrix(char ***matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		print_arr(matrix[i]);
		write(1, "\n", 1);
		i++;
	}
}
