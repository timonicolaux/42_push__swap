/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:17:08 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/15 14:02:29 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_closest_in_list(int num, t_list **lst)
{
	int		i;
	int		temp;
	int		index;
	t_list	*lst_copy;

	i = 0;
	lst_copy = *lst;
	temp = find_min(lst);
	index = find_index_with_num(lst, temp);
	while (lst_copy)
	{
		if (lst_copy->number > temp && lst_copy->number < num)
		{
			temp = lst_copy->number;
			index = i;
		}
		lst_copy = lst_copy->next;
		i++;
	}
	return (index);
}

int	find_closest_in_list2(int num, t_list **lst)
{
	int		i;
	int		temp;
	int		index;
	t_list	*lst_copy;

	i = 0;
	lst_copy = *lst;
	temp = find_max(lst);
	index = find_index_with_num(lst, temp);
	while (lst_copy)
	{
		if (lst_copy->number < temp && lst_copy->number > num)
		{
			temp = lst_copy->number;
			index = i;
		}
		lst_copy = lst_copy->next;
		i++;
	}
	return (index);
}

int	reorder_list_cost(t_list **lst)
{
	int	result;
	int	max_index;
	int	length;

	length = lst_length(lst);
	max_index = find_index_with_num(lst, find_max(lst));
	if (max_index >= (length / 2))
		result = length - max_index;
	else
		result = max_index;
	return (result);
}

int	check_double_move(int a_index, int b_index, t_list **a_lst, t_list **b_lst)
{
	int	a_moves;
	int	b_moves;
	int	result;

	if (b_index < (lst_length(b_lst) / 2))
		b_moves = b_index;
	else
		b_moves = lst_length(b_lst) - b_index;
	if (a_index < (lst_length(a_lst) / 2))
		a_moves = a_index;
	else
		a_moves = lst_length(a_lst) - a_index;
	if (b_moves > a_moves)
		result = a_moves;
	else
		result = b_moves;
	return (result);
}
