/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:38:31 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/15 10:58:06 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_list **a_lst, t_list **b_lst)
{
	int	length;

	length = lst_length(a_lst);
	if (length == 2)
	{
		if ((*a_lst)->number > (*a_lst)->next->number)
			do_sa(a_lst);
	}
	else if (length == 3)
		three_numbers(a_lst);
	else if (length == 4)
		four_numbers(a_lst, b_lst);
	else
		turk_algo(a_lst, b_lst);
}

void	three_numbers(t_list **lst)
{
	if (((*lst)->next->number < (*lst)->number) && ((*lst)->next->number < (*lst)->next->next->number) && ((*lst)->number < (*lst)->next->next->number))
		do_sa(lst);
	else if (((*lst)->next->number < (*lst)->number) && ((*lst)->next->number > (*lst)->next->next->number))
	{
		do_sa(lst);
		do_rra(lst);
	}
	else if (((*lst)->next->number < (*lst)->number) && ((*lst)->next->number < (*lst)->next->next->number))
		do_ra(lst);
	else if (((*lst)->next->number > (*lst)->number) && ((*lst)->next->number > (*lst)->next->next->number) && ((*lst)->number < (*lst)->next->next->number))
	{
		do_sa(lst);
		do_ra(lst);
	}
	else if (((*lst)->next->number > (*lst)->number) && ((*lst)->next->number > (*lst)->next->next->number) && ((*lst)->number > (*lst)->next->next->number))
		do_rra(lst);
}

void	four_numbers(t_list **a_lst, t_list **b_lst)
{
	do_pb(a_lst, b_lst);
	three_numbers(a_lst);
	do_pa(a_lst, b_lst);
	if ((*a_lst)->number > lst_last(a_lst)->number)
		do_ra(a_lst);
	else if (((*a_lst)->number < lst_last(a_lst)->number) && ((*a_lst)->number > lst_last(a_lst)->previous->number))
	{
		do_rra(a_lst);
		do_sa(a_lst);
		do_ra(a_lst);
		do_ra(a_lst);
	}
	else if ((*a_lst)->number > (*a_lst)->next->number)
		do_sa(a_lst);
}
