/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:02:40 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:06:18 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fn_length(long long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i += 1;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*last_fn(int i, char *ptr, long long int temp)
{
	ptr[i] = '\0';
	if (temp < 0)
	{
		temp = -temp;
		ptr[0] = '-';
	}
	if (temp == 0)
		ptr[0] = 48;
	while (temp != 0)
	{
		i--;
		ptr[i] = temp % 10 + 48;
		temp = temp / 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	int				size;
	int				i;
	long long int	temp;

	temp = n;
	size = fn_length(temp);
	ptr = 0;
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr == 0)
		return (0);
	i = size;
	ptr = last_fn(i, ptr, temp);
	return (ptr);
}

// char *ft_itoa(unsigned int nbr, int base)
// {
//     char *s = NULL;
//     unsigned int temp = nbr;
//     int digits = 0;

//     if (nbr == 0)
//         digits = 1;

//     while (temp != 0)
//     {
//         temp /= base;
//         digits++;
//     }
//     s = malloc(digits + 1);
//     s[digits] = '\0';
//     while (digits > 0)
//     {
//         if (nbr%base <= 9)
//             s[digits - 1] = nbr%base + 48;
//         else
//             s[digits -1] = nbr%base -10 + 'a';

//         digits--;
//         nbr /= base;
//     }
//     return s;
// }
