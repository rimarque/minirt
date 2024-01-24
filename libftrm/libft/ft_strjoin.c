/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:52:32 by rimarque          #+#    #+#             */
/*   Updated: 2023/07/01 13:47:06 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_s;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_s)
		return (0);
	ft_strlcpy(new_s, s1, (s1_len + 1));
	ft_strlcpy((new_s + s1_len), s2, (s2_len + 1));
	return (new_s);
}

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_s;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_s)
		return (0);
	ft_strlcpy(new_s, s1, (s1_len + 1));
	ft_strlcpy((new_s + s1_len), s2, (s2_len + 1));
	if (*s1)
		ft_free_str((char **)&s1);
	return (new_s);
}

char	**ft_arrjoin(char	**arr1, char	*str, char	**arr2)
{
	size_t	arr1_len;
	size_t	arr2_len;
	char	**new_arr;

	if (!arr1 || !str || !arr2)
		return (0);
	arr1_len = ft_arrlen(arr1);
	arr2_len = ft_arrlen(arr2);
	new_arr = malloc((arr1_len + arr2_len + 2) * sizeof(char *));
	if (!new_arr)
		return (0);
	ft_arrlcpy(new_arr, arr1, (arr1_len + 1));
	new_arr[arr1_len] = str;
	ft_arrlcpy(new_arr + arr1_len + 1, arr2, (arr2_len + 1));
	return (new_arr);
}
