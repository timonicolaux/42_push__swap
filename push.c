/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:23:03 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/05 13:17:11 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **a_list, t_list **b_list)
{
	t_list	*temp;

	if (!b_list)
		return ;
	temp = (*b_list)->next;
	ft_lstadd_front(a_list, *b_list);
	*b_list = temp;
	if (*b_list)
		(*b_list)->previous = NULL;
}

void	do_pa(t_list **a_list, t_list **b_list)
{
	push(a_list, b_list);
	printf("pa\n");
}

void	do_pb(t_list **a_list, t_list **b_list)
{
	push(b_list, a_list);
	printf("pb\n");
}
