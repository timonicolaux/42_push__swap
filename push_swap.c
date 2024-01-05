/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:26:21 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/05 10:51:51 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int ac, char **str, int i)
{
	int	start;
	t_list	*a_lst;
	t_list	*b_lst;
	t_list	*add_lst;

	start = i;
	while (str[i])
	{
		if (i == start)
		{
			a_lst = ft_lstnew(ft_atoi(str[i]));
		}
		else
		{
			add_lst = ft_lstnew(ft_atoi(str[i]));
			ft_lstadd_back(&a_lst, add_lst);
		}
		i++;
	}
	algo(&a_lst, &b_lst);
	i = start;
	while (str[i])
	{
		printf("%d\n", a_lst->number);
		a_lst = a_lst->next;
		i++;
	}
	return(0);
}

int	main(int ac, char **av)
{
	char	**numbers;

	if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		push_swap(ac, numbers, 0);
	}
	else if (ac > 2)
		push_swap(ac, av, 1);
	else
		printf("Please enter some values\n");
	return (0);
}
