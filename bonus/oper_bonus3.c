/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_bonus3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:04:43 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 20:04:48 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "checker.h"

static void	sub_rr_struct_a(t_ptrs s_ab)
{
	t_elm	*tmp_first;

	tmp_first = s_ab.a_ptr->head;
	s_ab.a_ptr->head = tmp_first->prev;
	tmp_first->prev->next = NULL;
	tmp_first->prev = NULL;
	tmp_first->next = s_ab.a_ptr->tail;
	s_ab.a_ptr->tail->prev = tmp_first;
	s_ab.a_ptr->tail = tmp_first;
}

void	ft_rr(t_ptrs s_ab)
{
	t_elm	*tmp_first;

	if (s_ab.a_ptr->length > 1 || s_ab.b_ptr->length > 1)
	{
		if (s_ab.a_ptr->length > 1)
			sub_rr_struct_a(s_ab);
		if (s_ab.b_ptr->length > 1)
		{
			tmp_first = s_ab.b_ptr->head;
			s_ab.b_ptr->head = tmp_first->prev;
			tmp_first->prev->next = NULL;
			tmp_first->prev = NULL;
			tmp_first->next = s_ab.b_ptr->tail;
			s_ab.b_ptr->tail->prev = tmp_first;
			s_ab.b_ptr->tail = tmp_first;
		}
	}
}

void	ft_ra(t_ptrs s_ab)
{
	t_elm	*tmp_first;

	if (s_ab.a_ptr->length > 1)
	{
		tmp_first = s_ab.a_ptr->head;
		s_ab.a_ptr->head = tmp_first->prev;
		tmp_first->prev->next = NULL;
		tmp_first->prev = NULL;
		tmp_first->next = s_ab.a_ptr->tail;
		s_ab.a_ptr->tail->prev = tmp_first;
		s_ab.a_ptr->tail = tmp_first;
	}
}

void	ft_rb(t_ptrs s_ab)
{
	t_elm	*tmp_first;

	if (s_ab.b_ptr->length > 1)
	{
		tmp_first = s_ab.b_ptr->head;
		s_ab.b_ptr->head = tmp_first->prev;
		tmp_first->prev->next = NULL;
		tmp_first->prev = NULL;
		tmp_first->next = s_ab.b_ptr->tail;
		s_ab.b_ptr->tail->prev = tmp_first;
		s_ab.b_ptr->tail = tmp_first;
	}
}
