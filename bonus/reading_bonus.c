/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:58:02 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 19:58:08 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"
#include "checker.h"

void	compare_line_commands(t_ptrs s_ab, char *new_line);

static void	bonus_stack_is_sorted2(t_ptrs s_ab)
{
	t_elm	*tmp;

	tmp = s_ab.a_ptr->head->prev;
	while (tmp)
	{
		if (tmp->next->number < tmp->number)
		{
			tmp = tmp->prev;
			if (tmp == 0)
			{
				write(1, "OK\n", 3);
				return ;
			}	
			continue ;
		}
		else
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
}

static void	bonus_stack_is_sorted(t_ptrs s_ab)
{
	int		size;

	size = s_ab.a_ptr->length + s_ab.b_ptr->length;
	if (s_ab.b_ptr->length != 0)
	{
		write(1, "KO\n", 3);
		return ;
	}
	if (s_ab.a_ptr->length == 1)
	{
		write(1, "OK\n", 3);
		return ;
	}
	bonus_stack_is_sorted2(s_ab);
}

void	bonus_free_exit(t_ptrs s_ab, char *new_line)
{
	t_elm	*tmp;

	while (s_ab.a_ptr->head)
	{
		tmp = s_ab.a_ptr->head;
		s_ab.a_ptr->head = s_ab.a_ptr->head->prev;
		free (tmp);
	}
	while (s_ab.b_ptr->head)
	{
		tmp = s_ab.b_ptr->head;
		s_ab.b_ptr->head = s_ab.b_ptr->head->prev;
		free (tmp);
	}
	if (new_line != NULL)
		free (new_line);
	exit(EXIT_SUCCESS);
}

void	bonus_free_exit_error(t_ptrs s_ab, char *new_line)
{
	t_elm	*tmp;

	while (s_ab.a_ptr->head)
	{
		tmp = s_ab.a_ptr->head;
		s_ab.a_ptr->head = s_ab.a_ptr->head->prev;
		free (tmp);
	}
	while (s_ab.b_ptr->head)
	{
		tmp = s_ab.b_ptr->head;
		s_ab.b_ptr->head = s_ab.b_ptr->head->prev;
		free (tmp);
	}
	if (new_line != NULL)
		free (new_line);
	ft_error(EXIT_FAILURE);
}

void	ft_reading_commands(t_ptrs s_ab)
{
	char	*new_line;

	while (1)
	{
		new_line = get_next_line(0);
		if (!new_line)
		{
			bonus_stack_is_sorted(s_ab);
			bonus_free_exit(s_ab, new_line);
			break ;
		}
		compare_line_commands(s_ab, new_line);
		free(new_line);
	}
}
