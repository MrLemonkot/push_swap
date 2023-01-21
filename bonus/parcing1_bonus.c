/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:01:20 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 20:01:33 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "checker.h"

int	check_chars(char *argv, int k, int *digit_flag, int *space_flag)
{
	if (argv[k] == '-' || argv[k] == '+' || argv[k] == ' '\
	|| ft_isdigit(argv[k]) == 1)
	{
		if (ft_isdigit(argv[k]) == 1 && *digit_flag == 0)
			*digit_flag = 1;
		if (argv[k] == ' ' && *space_flag == 0)
			*space_flag = 1;
		if (argv[k] == '-' || argv[k] == '+')
		{
			if (ft_isdigit(argv[k + 1]) == 0 || (k != 0 && argv[k - 1] != ' '))
				ft_error(1);
		}
		return (1);
	}
	ft_error(1);
	return (0);
}

void	ft_free(char **array, int size)
{
	while (array[++size] != NULL)
		free (array[size]);
	ft_error(EXIT_FAILURE);
}

char	**cycle_1(char **argv, int *space_flag, int size)
{
	int		k;
	int		digit_flag;
	char	**space_array;

	while (argv[++size])
	{
		k = -1;
		digit_flag = 0;
		while (argv[size][++k])
			check_chars(argv[size], k, &digit_flag, space_flag);
		if (digit_flag == 0)
			ft_error(EXIT_SUCCESS);
	}
	size = size - 1;
	space_array = (char **)malloc((size + 1) * sizeof(char *));
	if (space_array == 0)
		ft_malloc_error(EXIT_FAILURE);
	space_array[size] = NULL;
	while (--size >= 0)
	{
		space_array[size] = ft_strdup(argv[size + 1]);
		if (space_array[size] == NULL)
			ft_free(space_array, size);
	}
	return (space_array);
}
