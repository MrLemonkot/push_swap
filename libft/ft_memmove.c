/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:03:11 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:06:10 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_str;
	char		*dest_cross;
	const char	*src_str;
	char		*src_cross;

	if (dest == NULL && src == NULL)
		return (NULL);
	src_str = (const char *)src;
	dest_str = (char *)dest;
	if (dest_str < src_str)
	{
		while (n--)
			*dest_str++ = *src_str++;
	}
	else
	{
		src_cross = (char *)src_str + (n - 1);
		dest_cross = dest_str + (n - 1);
		while (n--)
			*dest_cross-- = *src_cross--;
	}
	return (dest);
}
