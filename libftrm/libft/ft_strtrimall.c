/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:38:53 by dinoguei          #+#    #+#             */
/*   Updated: 2023/08/10 21:38:53 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isspace(int c)
{
	return (c == '\t' || c == ' ' || c == '\n');
}

char	*ft_strtrimall(char *str)
{
	int	i;
	int	j;
	char *temp;
	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	if (str[i] && ft_isspace(str[i]))
		i++;
	j = ft_strlen(str);
	if (i >= j--)
		return(str);
	while (str[j] && ft_isspace(str[j]))
		j -= 1;
	temp = ft_substr(str, i, j + 1);
	free(str);
	return(temp);
}
