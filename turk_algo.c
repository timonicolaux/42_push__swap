/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:24:44 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/15 14:01:56 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_algo(t_list **a_lst, t_list **b_lst)
{
	int	length;
	int	i;

	length = lst_length(a_lst);
	i = 0;
	first_move(a_lst, b_lst);
	while (lst_length(a_lst) > 3)
		turk_algo_b(a_lst, b_lst);
	while (i < lst_length(b_lst))
	{
		if ((*b_lst)->number < (*b_lst)->next->number)
			do_rb(b_lst);
		else if (lst_last(b_lst)->number > (*b_lst)->number)
			do_rrb(b_lst);
		i++;
	}
	three_numbers(a_lst);
	turk_algo_a(a_lst, b_lst);
	while (length)
	{
		if ((*a_lst)->number > find_min(a_lst))
			do_rra(a_lst);
		length--;
	}
}

void	first_move(t_list **a_lst, t_list **b_lst)
{
	do_pb(a_lst, b_lst);
	do_pb(a_lst, b_lst);
	if ((*b_lst)->number < (*b_lst)->next->number)
		do_rb(b_lst);
}

void	turk_algo_b(t_list **a_lst, t_list **b_lst)
{
	t_list	*a_copy;
	int		cost;
	int		index;
	int		i;

	i = 0;
	a_copy = *a_lst;
	cost = calculate_cost(a_copy->number, b_lst, i, a_lst);
	index = i;
	while (i < lst_length(a_lst))
	{
		if (calculate_cost(a_copy->number, b_lst, i, a_lst) < cost)
		{
			cost = calculate_cost(a_copy->number, b_lst, i, a_lst);
			index = i;
		}
		a_copy = a_copy->next;
		i++;
	}
	push_to_b(a_lst, b_lst, index, lst_length(a_lst));
}

void	turk_algo_a(t_list **a_lst, t_list **b_lst)
{
	int	i;

	while ((*b_lst))
	{
		i = find_closest_in_list2((*b_lst)->number, a_lst);
		if ((*b_lst)->number > find_max(a_lst))
			do_pa(a_lst, b_lst);
		else if (i > (lst_length(a_lst) / 2))
		{
			i = lst_length(a_lst) - i;
			while (i--)
				do_rra(a_lst);
			do_pa(a_lst, b_lst);
		}
		else
		{
			while (i--)
				do_ra(a_lst);
			do_pa(a_lst, b_lst);
		}
	}
}
