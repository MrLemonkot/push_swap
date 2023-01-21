/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:25:16 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 20:25:25 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	check_exit_final_sorting_of_stack_a(t_stacks s_ab, t_dlist *ptr_stack)
{
	t_elm	*tmp;

	if (s_ab.a_ptr->length != s_ab.nbr_of_elmnts)
		return ;
	tmp = ptr_stack->head->prev;
	while (tmp)
	{
		if (tmp->next->sort_ind > tmp->sort_ind)
			break ;
		tmp = tmp->prev;
		if (tmp == 0)
			exit(EXIT_SUCCESS);
	}
}

char	three_stack_is_sorted(t_dlist *ptr_stack)
{
	t_elm	*tmp;

	if (ptr_stack == NULL)
		return ('0');
	if (ptr_stack->length < 2)
		return ('y');
	tmp = ptr_stack->head->prev;
	while (tmp)
	{
		if (tmp->next->sort_ind > tmp->sort_ind)
			break ;
		tmp = tmp->prev;
		if (tmp == 0)
			return ('y');
	}
	return ('n');
}

int	r_or_rr_stack_a(t_dlist *stack, int start_interval, int interval)
{
	t_elm	*tmp;
	int		help_position;

	help_position = 1;
	tmp = stack->head;
	while (tmp->sort_ind < start_interval || \
		tmp->sort_ind > start_interval + interval)
	{
		tmp = tmp->prev;
		help_position++;
		if (tmp == 0)
			break ;
	}
	return (help_position);
}

int	r_or_rr_stack_b(t_dlist *stack, int what_i)
{
	t_elm	*tmp;
	int		help_position;

	help_position = 1;
	tmp = stack->head;
	while (tmp->sort_ind != what_i)
	{
		tmp = tmp->prev;
		help_position++;
		if (tmp == 0)
			break ;
	}
	return (help_position);
}
