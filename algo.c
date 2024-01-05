/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:38:31 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/05 13:44:08 by tnicolau         ###   ########.fr       */
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
	if (length == 3)
		three_numbers(a_lst);
	else if (length == 4 || length == 5)
		four_five_numbers(a_lst, b_lst, length);
	// while (length)
	// {
	// 	printf("%d\n", (*lst)->number);
	// 	*lst = (*lst)->next;
	// 	length--;
	// }
	// printf("%d\n", (*lst)->number);
	// printf("%d\n", (*lst)->next->number);
	// printf("%d\n", (*lst)->next->next->number);
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

void	four_five_numbers(t_list **a_lst, t_list **b_lst, int length)
{
	int	length_copy;

	length_copy = length;
	while (length != 3)
	{
		do_pb(a_lst, b_lst);
		length--;
	}
	three_numbers(a_lst);
	while (length_copy != 3)
	{
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
		length_copy--;
	}
}
