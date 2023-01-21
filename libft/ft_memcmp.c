/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:02:57 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:06:14 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	const char		*new1;
	const char		*new2;
	size_t			i;

	new1 = (const char *)ptr1;
	new2 = (const char *)ptr2;
	if (n == 0)
		return (0);
	i = 0;
	while (i <= n - 1)
	{
		if (new1[i] != new2[i])
			return ((unsigned char)new1[i] - (unsigned char)new2[i]);
		i++;
	}
	return (0);
}
