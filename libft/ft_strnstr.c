/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:04:47 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:05:34 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*f(const char *big, const char *little, size_t len_l, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	temp;

	i = 0;
	k = 0;
	while (i <= (len - len_l))
	{
		temp = i;
		while (big[i] == little[k])
		{
			if (k == len_l - 1)
				return ((char *)(big + temp));
			i++;
			k++;
		}
		k = 0;
		i = temp + 1;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_l;
	size_t	len_big;

	if (*little == 0)
		return ((char *)big);
	len_big = ft_strlen((char *)big);
	len_l = ft_strlen((char *)little);
	if (len > len_big)
		len = len_big;
	if (len < len_l)
		return (0);
	return (f(big, little, len_l, len));
}
