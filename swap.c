/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timonicolaux <timonicolaux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:18:09 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/14 11:27:15 by timonicolau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	int	number;

	if (!(*lst) || !(*lst)->next)
		return ;
	number = (*lst)->next->number;
	(*lst)->next->number = (*lst)->number;
	(*lst)->number = number;
}

void	do_sa(t_list **lst)
{
	swap(lst);
	printf("sa\n");
}

void	do_sb(t_list **lst)
{
	swap(lst);
	printf("sb\n");
}

void	do_ss(t_list **a_stack, t_list **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	printf("ss\n");
}

