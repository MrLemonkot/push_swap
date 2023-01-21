/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_bonus1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:03:40 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 20:03:50 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "checker.h"

void	ft_sa(t_ptrs s_ab)
{
	int		ind;
	int		value;

	if (s_ab.a_ptr->length >= 2)
	{
		ind = s_ab.a_ptr->head->prev->sort_ind;
		value = s_ab.a_ptr->head->prev->number;
		s_ab.a_ptr->head->prev->number = s_ab.a_ptr->head->number;
		s_ab.a_ptr->head->prev->sort_ind = s_ab.a_ptr->head->sort_ind;
		s_ab.a_ptr->head->number = value;
		s_ab.a_ptr->head->sort_ind = ind;
	}
}

void	ft_sb(t_ptrs s_ab)
{
	int		ind;
	int		value;

	if (s_ab.b_ptr->length >= 2)
	{
		ind = s_ab.b_ptr->head->prev->sort_ind;
		value = s_ab.b_ptr->head->prev->number;
		s_ab.b_ptr->head->prev->number = s_ab.b_ptr->head->number;
		s_ab.b_ptr->head->prev->sort_ind = s_ab.b_ptr->head->sort_ind;
		s_ab.b_ptr->head->number = value;
		s_ab.b_ptr->head->sort_ind = ind;
	}
}

void	ft_ss(t_ptrs s_ab)
{
	int		ind;
	int		value;

	if (s_ab.b_ptr->length >= 2 || s_ab.a_ptr->length >= 2)
	{
		if (s_ab.a_ptr->length >= 2)
		{
			ind = s_ab.a_ptr->head->prev->sort_ind;
			value = s_ab.a_ptr->head->prev->number;
			s_ab.a_ptr->head->prev->number = s_ab.a_ptr->head->number;
			s_ab.a_ptr->head->prev->sort_ind = s_ab.a_ptr->head->sort_ind;
			s_ab.a_ptr->head->number = value;
			s_ab.a_ptr->head->sort_ind = ind;
		}
		if (s_ab.b_ptr->length >= 2)
		{
			ind = s_ab.b_ptr->head->prev->sort_ind;
			value = s_ab.b_ptr->head->prev->number;
			s_ab.b_ptr->head->prev->number = s_ab.b_ptr->head->number;
			s_ab.b_ptr->head->prev->sort_ind = s_ab.b_ptr->head->sort_ind;
			s_ab.b_ptr->head->number = value;
			s_ab.b_ptr->head->sort_ind = ind;
		}
	}
}

void	ft_pb(t_ptrs s_ab)
{
	t_elm	*tmp;

	if (s_ab.a_ptr->length > 0)
	{
		tmp = s_ab.a_ptr->head;
		tmp->next = NULL;
		s_ab.a_ptr->head = tmp->prev;
		if (s_ab.a_ptr->length == 1)
			s_ab.a_ptr->tail = NULL;
		else
			tmp->prev->next = NULL;
		if (s_ab.b_ptr->length == 0)
			s_ab.b_ptr->tail = tmp;
		else
			s_ab.b_ptr->head->next = tmp;
		tmp->prev = s_ab.b_ptr->head;
		s_ab.b_ptr->head = tmp;
		s_ab.a_ptr->length -= 1;
		s_ab.b_ptr->length += 1;
	}
}

void	ft_pa(t_ptrs s_ab)
{
	t_elm	*tmp;

	if (s_ab.b_ptr->length > 0)
	{
		tmp = s_ab.b_ptr->head;
		tmp->next = NULL;
		s_ab.b_ptr->head = tmp->prev;
		if (s_ab.b_ptr->length == 1)
			s_ab.b_ptr->tail = NULL;
		else
			tmp->prev->next = NULL;
		if (s_ab.a_ptr->length == 0)
			s_ab.a_ptr->tail = tmp;
		else
			s_ab.a_ptr->head->next = tmp;
		tmp->prev = s_ab.a_ptr->head;
		s_ab.a_ptr->head = tmp;
		s_ab.b_ptr->length -= 1;
		s_ab.a_ptr->length += 1;
	}
}
