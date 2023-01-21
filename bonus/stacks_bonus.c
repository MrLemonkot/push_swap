/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:36:35 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 19:36:50 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"

void	*ft_calloc(size_t n, size_t size);

void	free_exit_yes_no(int *arr, t_elm *tail_a, char c)
{
	t_elm	*tmp;

	if (arr != NULL)
	{
		free (arr);
		arr = NULL;
	}
	while (tail_a)
	{
		tmp = tail_a;
		tail_a = tail_a->next;
		free (tmp);
	}
	if (c == 'm')
		ft_malloc_error(EXIT_FAILURE);
	if (c == 'y')
		ft_error(EXIT_SUCCESS);
}

void	create_first_elm_add_to_stack_a(t_ptrs s_ab_arr)
{
	t_elm	*ptr_on_first_elem;

	ptr_on_first_elem = (t_elm *)ft_calloc(1, sizeof(t_elm));
	if (ptr_on_first_elem == NULL)
		free_exit_yes_no(s_ab_arr.int_arr, NULL, 'm');
	ptr_on_first_elem->number = s_ab_arr.int_arr[0];
	s_ab_arr.a_ptr->length = 1;
	s_ab_arr.a_ptr->head = ptr_on_first_elem;
	s_ab_arr.a_ptr->tail = ptr_on_first_elem;
	return ;
}

void	create_elements_for_stack_a(t_ptrs s_ab_arr, int i, t_elm *first_ptr)
{
	t_elm	*ptr_on_new;

	ptr_on_new = (t_elm *)calloc(1, sizeof(t_elm));
	if (ptr_on_new == NULL)
		free_exit_yes_no(s_ab_arr.int_arr, s_ab_arr.a_ptr->tail, 'm');
	if (i == 1)
		first_ptr->prev = ptr_on_new;
	ptr_on_new->number = s_ab_arr.int_arr[i];
	ptr_on_new->next = s_ab_arr.a_ptr->tail;
	ptr_on_new->prev = NULL;
	s_ab_arr.a_ptr->tail->prev = ptr_on_new;
	s_ab_arr.a_ptr->tail = ptr_on_new;
	s_ab_arr.a_ptr->length += 1;
	return ;
}

void	fill_stack_a_other_elms(t_ptrs s_ab_arr, int size)
{
	int	i;

	i = 1;
	while (i < (size))
	{
		create_elements_for_stack_a(s_ab_arr, i, s_ab_arr.a_ptr->head);
		i++;
	}
}

void	create_stacks_operations(int *int_array, int *size)
{
	t_dlist	struct_b;
	t_dlist	struct_a;
	t_ptrs	s_ab_arr;

	struct_b.length = 0;
	struct_b.head = NULL;
	struct_b.tail = NULL;
	struct_a.length = 0;
	struct_a.head = NULL;
	struct_a.tail = NULL;
	s_ab_arr.a_ptr = &struct_a;
	s_ab_arr.b_ptr = &struct_b;
	s_ab_arr.int_arr = int_array;
	create_first_elm_add_to_stack_a(s_ab_arr);
	fill_stack_a_other_elms(s_ab_arr, *size);
	free_exit_yes_no(s_ab_arr.int_arr, NULL, 'n');
	ft_reading_commands(s_ab_arr);
}
