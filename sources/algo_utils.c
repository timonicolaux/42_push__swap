/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:49:13 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/15 10:57:45 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_list **a_lst, t_list **b_lst, int index, int length)
{
	t_list	*a_copy;

	a_copy = *a_lst;
	a_copy = a_copy->next;
	if (index < (length / 2))
		first_a_half(a_lst, b_lst, index);
	else
		second_a_half(a_lst, b_lst, index, length);
	if ((*a_lst)->number < find_min(b_lst))
		reorder_b_with_min(b_lst);
	else
		reorder_b_with_else(a_lst, b_lst);
	do_pb(a_lst, b_lst);
}

void	first_a_half(t_list **a_lst, t_list **b_lst, int index)
{
	int	a_num;
	int	b_index;
	int	double_moves;

	a_num = find_num_with_index(a_lst, index);
	b_index = find_closest_in_list(a_num, b_lst);
	double_moves = check_double_move(index, b_index, a_lst, b_lst);
	if (b_index >= (lst_length(b_lst) / 2))
		double_moves = 0;
	index = index - double_moves;
	while (double_moves > 0)
	{
		do_rr(a_lst, b_lst);
		double_moves--;
	}
	while (index)
	{
		do_ra(a_lst);
		index--;
	}
}

void	second_a_half(t_list **a_lst, t_list **b_lst, int index, int length)
{
	int	a_num;
	int	b_index;
	int	double_moves;

	a_num = find_num_with_index(a_lst, index);
	b_index = find_closest_in_list(a_num, b_lst);
	double_moves = check_double_move(index, b_index, a_lst, b_lst);
	if (b_index < (lst_length(b_lst) / 2))
		double_moves = 0;
	index = index + double_moves;
	while (double_moves > 0)
	{
		do_rrr(a_lst, b_lst);
		double_moves--;
	}
	while (index < (length - 1))
	{
		do_rra(a_lst);
		index++;
	}
}

void	reorder_b_with_min(t_list **b_lst)
{
	int	b_index;

	b_index = find_index_with_num(b_lst, find_max(b_lst));
	if (b_index >= (lst_length(b_lst) / 2))
	{
		b_index = lst_length(b_lst) - b_index;
		while (b_index)
		{
			do_rrb(b_lst);
			b_index--;
		}
	}
	else
	{
		while (b_index)
		{
			do_rb(b_lst);
			b_index--;
		}
	}
}

void	reorder_b_with_else(t_list **a_lst, t_list **b_lst)
{
	int	i;

	i = find_closest_in_list((*a_lst)->number, b_lst);
	if (i > (lst_length(b_lst) / 2))
	{
		i = lst_length(b_lst) - i;
		while (i)
		{
			do_rrb(b_lst);
			i--;
		}
	}
	else
	{
		while (i)
		{
			do_rb(b_lst);
			i--;
		}
	}
}
