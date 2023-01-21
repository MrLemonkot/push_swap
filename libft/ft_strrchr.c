/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:04:54 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:05:30 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*ptr;

	ptr = str + ft_strlen((char *)str);
	while (ptr >= str)
	{
		if (*ptr == (char)c)
			return ((char *)ptr);
		else
			ptr--;
	}
	return (0);
}
