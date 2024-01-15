/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:41:03 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/15 10:24:00 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list **lst)
{
	int	i;
	t_list	*lst_copy;

	lst_copy = *lst;
	i = lst_copy->number;
	while (lst_copy)
	{
		if (lst_copy->number < i)
			i = lst_copy->number;
		lst_copy = lst_copy->next;
	}
	return (i);
}

int	find_max(t_list **lst)
{
	int	i;
	t_list	*lst_copy;

	lst_copy = *lst;
	i = lst_copy->number;
	while (lst_copy)
	{
		if (lst_copy->number > i)
			i = lst_copy->number;
		lst_copy = lst_copy->next;
	}
	return (i);
}

int	find_num_with_index(t_list **lst, int index)
{
	t_list	*lst_copy;
	int		i;

	lst_copy = *lst;
	i = 0;
	while (i < index)
	{
		lst_copy = lst_copy->next;
		i++;
	}
	return (lst_copy->number);
}

int	find_index_with_num(t_list **lst, int num)
{
	t_list	*lst_copy;
	int		i;

	lst_copy = *lst;
	i = 0;
	while (lst_copy->number != num)
	{
		lst_copy = lst_copy->next;
		i++;
	}
	return (i);
}
