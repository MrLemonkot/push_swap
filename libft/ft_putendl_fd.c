/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:03:28 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:06:05 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	perenos;

	if (s != NULL)
	{
		perenos = '\n';
		write(fd, s, ft_strlen(s));
		write(fd, &perenos, 1);
	}
}
