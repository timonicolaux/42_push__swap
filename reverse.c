/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timonicolaux <timonicolaux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:00:34 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/14 11:27:25 by timonicolau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_list **lst)
{
	t_list	*last;

	if (!(*lst) || !(*lst)->next)
		return ;
	last = lst_last(lst);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *lst;
	(*lst)->previous = last;
	*lst = (*lst)->previous;
}

void	do_rra(t_list **lst)
{
	reverse(lst);
	printf("rra\n");
}

void	do_rrb(t_list **lst)
{
	reverse(lst);
	printf("rrb\n");
}

void	do_rrr(t_list **a_list, t_list **b_list)
{
	reverse(a_list);
	reverse(b_list);
	printf("rrr\n");
}
