/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:00:34 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/15 11:03:31 by tnicolau         ###   ########.fr       */
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
	ft_printf("rra\n");
}

void	do_rrb(t_list **lst)
{
	reverse(lst);
	ft_printf("rrb\n");
}

void	do_rrr(t_list **a_list, t_list **b_list)
{
	reverse(a_list);
	reverse(b_list);
	ft_printf("rrr\n");
}
