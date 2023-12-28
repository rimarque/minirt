/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:39:42 by rimarque          #+#    #+#             */
/*   Updated: 2023/07/03 22:28:13 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strcount(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	while (*s == c && *s)
		s++;
	count = 0;
	while (*s)
	{
		if (ft_strchr(s, c))
		{
			count++;
			s = ft_strchr(s, c);
			while (*s == c && *s)
				s++;
		}
		else
			s++;
	}
	return (count + 1);
}

char	**ft_makesplit(char	**split, char const *s, char c)
{
	size_t	x;
	size_t	len;

	x = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		len = ft_strclen(s, c);
		if (len != 0)
		{
			split[x] = ft_calloc((len + 1), sizeof(char));
			ft_strlcpy(split[x], ((char *)s), (len + 1));
			s = s + len;
			x++;
		}
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (0);
	split = ft_calloc((ft_strcount(s, c) + 1), sizeof(char *));
	if (!split)
		return (0);
	split = ft_makesplit(split, s, c);
	return (split);
}

/*int	main()
{
	char	**split;
	char	c;
	size_t	i;

	c = ' ';
	split = ft_quotes("awk '{count++} END {print count}'", c);
	//split =
	i = 0;
	while (split[i] != 0)
	{
		printf("%s\n", split[i]);
		i++;
	}
	ft_free_array(&split);
	return (0);
}*/
