/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:58:01 by dinoguei          #+#    #+#             */
/*   Updated: 2023/12/19 19:03:18 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	int		i;
	char	*out;

	i = 0;
	if (!str || !f)
		return (NULL);
	out = malloc((ft_strlen((char *)str) + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		out[i] = f(i, str[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
