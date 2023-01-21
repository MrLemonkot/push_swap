/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:59:47 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:00:18 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	size_n;

	size_n = n * size;
	ptr = malloc(size_n);
	if (ptr == 0)
		return (0);
	return (ft_memset(ptr, 0, size_n));
}
