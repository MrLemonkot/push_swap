/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:05:05 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:05:26 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	length_str;

	if (str == NULL)
	{
		return (NULL);
	}
	length_str = ft_strlen((char *)str);
	sub_str = 0;
	if (start > length_str)
	{
		sub_str = (char *)malloc(sizeof(char) * 1);
		if (sub_str == 0)
			return (0);
		*sub_str = 0;
		return (sub_str);
	}
	if ((length_str - start + 1) < len)
		len = length_str - start + 1;
	sub_str = 0;
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (sub_str == 0)
		return (0);
	ft_strlcpy(sub_str, str + start, len + 1);
	return (sub_str);
}
