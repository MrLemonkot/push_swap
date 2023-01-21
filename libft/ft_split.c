/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:03:45 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:05:57 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**malloc_create_arr(char **arr,
	const char *src, size_t count_new_strings, char c)
{
	int		i;
	size_t	k;

	k = 0;
	while (k < count_new_strings)
	{
		while (*src == c && *src != '\0')
			src++;
		i = 0;
		while (src[i] != '\0' && src[i] != c)
			i++;
		arr[k] = (char *)malloc(sizeof(char) * (i + 1));
		if (arr[k] == 0)
		{
			while (arr[k-- - 1])
				free(arr[k - 1]);
			return (0);
		}			
		ft_strlcpy(arr[k], src, i + 1);
		k++;
		src = (char *)ft_strchr(src, c);
	}
	arr[k] = 0;
	return (arr);
}

static size_t	count_new_strings(const char *src, char c)
{
	size_t	n;

	n = 0;
	while (1)
	{
		while (*src == c && *src != '\0')
			src++;
		if (ft_strlen((char *)src) == 0)
			break ;
		n++;
		if (ft_strchr((char *)src, c) == NULL)
			break ;
		src = ft_strchr(src, c);
	}
	return (n);
}

char	**ft_split(char const *src, char c)
{
	char	**arr;
	size_t	n;

	if (src == NULL)
		return (0);
	n = count_new_strings((char *)src, c);
	arr = (char **)malloc(sizeof(char *) * (n + 1));
	if (arr == 0)
		return (0);
	return (malloc_create_arr(arr, src, n, c));
}
