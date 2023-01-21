/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:03:34 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:06:02 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	how_many_digits_module_no_n_0(unsigned int temp)
{
	int	i;

	i = 0;
	while (temp != 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

void	fill_arr_write(char *arr_n, unsigned int temp, int fd)
{
	int	last;
	int	i;

	last = how_many_digits_module_no_n_0(temp);
	arr_n[last] = '\0';
	i = 1;
	while (temp != 0)
	{
		arr_n[last - i] = temp % 10 + 48;
		temp = temp / 10;
		i++;
	}
	i = 0;
	while (arr_n[i] != 0)
	{
		write(fd, &arr_n[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	temp;
	char			c;
	char			arr_n[11];

	if (0 == n)
	{
		c = 48;
		write(fd, &c, 1);
		return ;
	}
	if (n < 0)
	{
		c = 45;
		write(fd, &c, 1);
		n = -n;
	}
	temp = n;
	fill_arr_write(arr_n, temp, fd);
}
