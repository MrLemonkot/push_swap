/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:03:04 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:06:12 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_str;
	const char	*src_str;

	if (dest == 0 && src == 0)
		return (NULL);
	dest_str = (char *)dest;
	src_str = (const char *)src;
	while (n--)
		*dest_str++ = *src_str++;
	return (dest);
}
