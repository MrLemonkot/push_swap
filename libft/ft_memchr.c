/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:02:49 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:06:16 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const char	*charptr;

	charptr = (const char *)ptr;
	while (n--)
	{
		while (*charptr == (char)c)
			return ((void *)charptr);
		charptr += 1;
	}
	return (0);
}
