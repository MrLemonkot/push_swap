/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:04:13 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:05:45 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	ldest;
	size_t	lsrc;

	ldest = ft_strlen(dest);
	lsrc = ft_strlen((char *)src);
	if (size <= ldest)
		return (size + lsrc);
	if (size > ldest)
		ft_strlcpy(dest + ldest, src, size - ldest);
	return (ldest + lsrc);
}
