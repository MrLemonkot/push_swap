/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:04:23 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:05:43 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	lsrc;

	lsrc = ft_strlen((char *)src);
	if (size == 0)
	{
		return (lsrc);
	}
	if (lsrc == 0)
	{
		dest[0] = '\0';
		return (lsrc);
	}
	if (size < lsrc + 1)
	{	
		ft_memmove(dest, src, size - 1);
		dest[size - 1] = '\0';
		return (lsrc);
	}
	ft_memmove(dest, src, lsrc);
	dest[lsrc] = '\0';
	return (lsrc);
}
