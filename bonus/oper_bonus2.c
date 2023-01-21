/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:04:05 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 20:04:15 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "checker.h"

void	ft_rra(t_ptrs s_ab)
{
	t_elm	*temp_last;

	if (s_ab.a_ptr->length > 1)
	{
		temp_last = s_ab.a_ptr->tail;
		s_ab.a_ptr->tail = s_ab.a_ptr->tail->next;
		temp_last->next->prev = NULL;
		temp_last->prev = s_ab.a_ptr->head;
		s_ab.a_ptr->head->next = temp_last;
		temp_last->next = NULL;
		s_ab.a_ptr->head = temp_last;
	}
}

void	ft_rrb(t_ptrs s_ab)
{
	t_elm	*temp_last;

	if (s_ab.b_ptr->length > 1)
	{
		temp_last = s_ab.b_ptr->tail;
		s_ab.b_ptr->tail = s_ab.b_ptr->tail->next;
		temp_last->next->prev = NULL;
		temp_last->prev = s_ab.b_ptr->head;
		s_ab.b_ptr->head->next = temp_last;
		temp_last->next = NULL;
		s_ab.b_ptr->head = temp_last;
	}
}

static void	sub_rrr_struct_a(t_ptrs s_ab)
{
	t_elm	*temp_last;

		temp_last = s_ab.a_ptr->tail;
		s_ab.a_ptr->tail = s_ab.a_ptr->tail->next;
		temp_last->next->prev = NULL;
		temp_last->prev = s_ab.a_ptr->head;
		s_ab.a_ptr->head->next = temp_last;
		temp_last->next = NULL;
		s_ab.a_ptr->head = temp_last;
}

void	ft_rrr(t_ptrs s_ab)
{
	t_elm	*temp_last;

	if (s_ab.b_ptr->length > 1 || s_ab.a_ptr->length > 1)
	{
		if (s_ab.a_ptr->length > 1)
			sub_rrr_struct_a(s_ab);
		if (s_ab.b_ptr->length > 1)
		{
			temp_last = s_ab.b_ptr->tail;
			s_ab.b_ptr->tail = s_ab.b_ptr->tail->next;
			temp_last->next->prev = NULL;
			temp_last->prev = s_ab.b_ptr->head;
			s_ab.b_ptr->head->next = temp_last;
			temp_last->next = NULL;
			s_ab.b_ptr->head = temp_last;
		}
	}
}
