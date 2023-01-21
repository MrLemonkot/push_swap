/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:59:21 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:00:31 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	power(int a, int n)
{
	if (n == 0)
		return (1);
	return (a * power(a, n - 1));
}

static int	find_end_number(char znak, const char *ptr)
{
	int	nbr;
	int	i;

	i = 0;
	while (*ptr >= 48 && *ptr <= 57)
	{
		i++;
		ptr++;
	}
	ptr = ptr - i;
	nbr = 0;
	while (i > 0)
	{
		nbr += (*ptr - 48) * power(10, i - 1);
		ptr++;
		i--;
	}
	if (znak == '-')
		nbr = -nbr;
	return (nbr);
}

static int	if_znak_is_found(const char *ptr)
{
	char	znak;

	if (*ptr == '+')
		znak = '+';
	else
		znak = '-';
	ptr = ptr + 1;
	while (*ptr == 48)
		ptr++;
	if (*ptr >= 49 && *ptr <= 57)
		return (find_end_number(znak, ptr));
	return (0);
}

int	ft_atoi(const char *ptr)
{
	while (*ptr == '-' || *ptr == '+' || *ptr == 48 || (*ptr >= 49
			&& *ptr <= 57) || (*ptr >= 9 && *ptr <= 13) || *ptr == 32)
	{
		if (*ptr == '-' || *ptr == '+')
			return (if_znak_is_found(ptr));
		if (*ptr >= 49 && *ptr <= 57)
			return (find_end_number('+', ptr));
		if (*ptr == 48)
		{
			while (*ptr == 48)
				ptr++;
			if (*ptr >= 49 && *ptr <= 57)
				return (find_end_number('+', ptr));
			return (0);
		}
		ptr++;
	}
	return (0);
}
