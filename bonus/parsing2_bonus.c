/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:01:59 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 20:02:02 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "checker.h"

char	*join_space(char **array, char *str)
{
	int		i;
	char	*tmp;
	char	*old_str;

	i = 0;
	while (array[i])
	{
		old_str = array[i];
		array[i] = ft_strjoin(array[i], " ");
		if (array[i] == NULL)
		{
			while (--i >= 0)
				free(array[i]);
			ft_malloc_error(EXIT_FAILURE);
		}
		tmp = str;
		str = ft_strjoin(str, array[i]);
		free(array[i++]);
		free(tmp);
		free (old_str);
	}
	return (str);
}

char	**cycle_2(char **array)
{
	int		i;
	char	**array_split;
	char	*str;

	str = ft_calloc(1, 1);
	i = 0;
	if (str == NULL)
	{
		while (array[i])
			free (array[i++]);
	}
	str = join_space(array, str);
	array_split = ft_split(str, ' ');
	free (str);
	free (array);
	if (array_split == 0)
		ft_malloc_error(EXIT_FAILURE);
	return (array_split);
}

void	ft_is_sorted(int *int_arr, char **array, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (int_arr[i] >= int_arr[i - 1])
		{
			if (i++ == size - 1)
			{
				while (--i >= 0)
					free (array[i]);
				free (int_arr);
				exit(EXIT_SUCCESS);
			}
			continue ;
		}
		else
			return ;
	}
}

void	check_dubble(int size, int *int_arr, char **array)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (i < size)
	{
		f = i - 1;
		while (f >= 0)
		{
			if (int_arr[i] == int_arr[f--])
			{
				free (int_arr);
				i = 0;
				while (i < size)
					free (array[i++]);
				free (array);
				ft_error(EXIT_SUCCESS);
			}
		}
		i++;
	}
}

int	*check_int_dubble(char **array, int *size)
{
	int	size_copy;
	int	*int_arr;
	int	i;

	size_copy = 0;
	i = 0;
	while (array[size_copy])
		*size = ++size_copy;
	int_arr = (int *)malloc(size_copy * sizeof(int));
	if (int_arr == NULL)
	{
		while (i < *size)
			free(array[i++]);
		free(array);
		ft_malloc_error(EXIT_FAILURE);
	}
	while (size_copy-- > 0)
		int_arr[size_copy] = atoi_overflow(array[size_copy], array, int_arr);
	check_dubble(*size, int_arr, array);
	while (i < *size)
		free (array[i++]);
	free (array);
	return (int_arr);
}
