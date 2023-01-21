/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:03:16 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:06:09 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*byte_str;

	byte_str = (char *)b;
	i = 0;
	while (i < len)
	{
		*(byte_str + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
