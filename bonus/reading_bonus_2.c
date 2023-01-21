/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_bonus_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:58:22 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 19:58:26 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../libft/libft.h"

void	bonus_free_exit_error(t_ptrs s_ab, char *new_line);

void	compare_reverse(t_ptrs s_ab, char *new_line)
{
	if (*(new_line + 1) == 'r')
	{
		if (*(new_line + 2) == 'r')
			ft_rrr(s_ab);
		else if (*(new_line + 2) == 'a')
			ft_rra(s_ab);
		else if (*(new_line + 2) == 'b')
			ft_rrb(s_ab);
		else
			bonus_free_exit_error(s_ab, new_line);
	}
	else
		bonus_free_exit_error(s_ab, new_line);
}

void	compare_rotate(t_ptrs s_ab, char *new_line)
{
	if (ft_strlen(new_line) == 3)
	{
		if (*(new_line + 1) == 'r')
			ft_rr(s_ab);
		else if (*(new_line + 1) == 'a')
			ft_ra(s_ab);
		else if (*(new_line + 1) == 'b')
			ft_rb(s_ab);
		else
			bonus_free_exit_error(s_ab, new_line);
	}
	else if (ft_strlen(new_line) == 4)
		compare_reverse(s_ab, new_line);
	else
		bonus_free_exit_error(s_ab, new_line);
}

void	compare_push(t_ptrs s_ab, char *new_line)
{
	if (ft_strlen(new_line) == 3)
	{
		if (*(new_line + 1) == 'a')
			ft_pa(s_ab);
		else if (*(new_line + 1) == 'b')
			ft_pb(s_ab);
		else
			bonus_free_exit_error(s_ab, new_line);
	}
	else
		bonus_free_exit_error(s_ab, new_line);
}

void	compare_switch(t_ptrs s_ab, char *new_line)
{
	if (ft_strlen(new_line) != 3)
		bonus_free_exit_error(s_ab, new_line);
	if (*(new_line + 1) == 's')
		ft_ss(s_ab);
	else if (*(new_line + 1) == 'a')
		ft_sa(s_ab);
	else if (*(new_line + 1) == 'b')
		ft_sb(s_ab);
	else
		bonus_free_exit_error(s_ab, new_line);
}

void	compare_line_commands(t_ptrs s_ab, char *new_line)
{
	if (*new_line == 's')
		compare_switch(s_ab, new_line);
	else if (*new_line == 'p')
		compare_push(s_ab, new_line);
	else if (*new_line == 'r')
		compare_rotate(s_ab, new_line);
	else
		bonus_free_exit_error(s_ab, new_line);
}
