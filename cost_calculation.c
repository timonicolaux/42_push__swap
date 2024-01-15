/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:28:13 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/15 10:25:45 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(int number, t_list **b_lst, int index, t_list **a_lst)
{
	int	cost;
	int	length;

	length = lst_length(a_lst);
	cost = 0;

	if (index < (length / 2))
		cost = check_first_half(number, b_lst, index, a_lst);
	else
		cost = check_first_half(number, b_lst, index, a_lst);
	return (cost);
}

int	check_first_half(int number, t_list **b_lst, int index, t_list **a_lst)
{
	int	cost;
	int	double_move;

	cost = 0;
	if (number < find_min(b_lst))
	{
		cost += reorder_list_cost(b_lst);
		cost += 1 + index;
	}
	else
	{
		cost += find_closest_in_list(number, b_lst);
		if (cost > (lst_length(b_lst) / 2))
			cost = lst_length(b_lst) - cost;
		else
		{
			double_move = check_double_move(cost, index, a_lst, b_lst);
			cost = cost - double_move;
		}
		cost += index + 1;
	}
	return (cost);
}

int	check_second_half(int number, t_list **b_lst, int index, t_list **a_lst)
{
	int	cost;
	int	double_move;
	int	length;

	cost = 0;
	length = lst_length(a_lst);
	if (number < find_min(b_lst))
	{
		cost += reorder_list_cost(b_lst);
		cost += 1 + ((length - 1) - index);
	}
	else
	{
		cost += find_closest_in_list(number, b_lst);
		if (cost > (lst_length(b_lst) / 2))
		{
			double_move = check_double_move(cost, index, a_lst, b_lst);
			cost = cost - double_move;
		}
		cost += ((length + 2) - index);
	}
	return (cost);
}
