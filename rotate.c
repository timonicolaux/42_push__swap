/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:15:44 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/15 11:52:32 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*last;

	if (!(*lst) || !(*lst)->next)
		return ;
	last = lst_last(lst);
	last->next = *lst;
	*lst = (*lst)->next;
	(*lst)->previous = NULL;
	last->next->previous = last;
	last->next->next = NULL;
}

void	do_ra(t_list **lst)
{
	rotate(lst);
	ft_printf("ra\n");
}

void	do_rb(t_list **lst)
{
	rotate(lst);
	ft_printf("rb\n");
}

void	do_rr(t_list **a_list, t_list **b_list)
{
	rotate(a_list);
	rotate(b_list);
	ft_printf("rr\n");
}
