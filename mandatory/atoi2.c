/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:13:05 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 20:13:17 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	min_max_int_error(int error, char **arr_split, int *int_arr);

char	sub_ft_1(char *ptr, char **arr_split, int *int_arr)
{
	if (ptr[0] > '2')
		min_max_int_error(EXIT_SUCCESS, arr_split, int_arr);
	if (ptr[0] < '2')
		return ('o');
	if (ptr[1] > '1')
		min_max_int_error(EXIT_SUCCESS, arr_split, int_arr);
	if (ptr[1] == '0')
		return ('o');
	if (ptr[2] > '4')
		min_max_int_error(EXIT_SUCCESS, arr_split, int_arr);
	if (ptr[2] < '4')
		return ('o');
	if (ptr[3] > '7')
		min_max_int_error(EXIT_SUCCESS, arr_split, int_arr);
	if (ptr[3] < '7')
		return ('o');
	if (ptr[4] > '4')
		min_max_int_error(EXIT_SUCCESS, arr_split, int_arr);
	if (ptr[4] < '4')
		return ('o');
	return ('n');
}

void	check_min_max_int(char *ptr, char *znak, char **arr_split, int *int_arr)
{
	if (sub_ft_1(ptr, arr_split, int_arr) == 'o')
		return ;
	if (ptr[5] > '8')
		min_max_int_error(EXIT_SUCCESS, arr_split, int_arr);
	if (ptr && (ptr[5] < '8'))
		return ;
	if (ptr && (ptr[6] > '3'))
		min_max_int_error(EXIT_SUCCESS, arr_split, int_arr);
	if (ptr[6] < '3')
		return ;
	if (ptr[7] > '6')
		min_max_int_error(EXIT_SUCCESS, arr_split, int_arr);
	if (ptr[7] < '6')
		return ;
	if (ptr[8] > '4')
		min_max_int_error(EXIT_SUCCESS, arr_split, int_arr);
	if (ptr[8] < '4')
		return ;
	if (*znak == '-' && ptr[9] <= '8')
		return ;
	if (*znak == '+' && ptr[9] <= '7')
		return ;
	min_max_int_error(EXIT_SUCCESS, arr_split, int_arr);
}
