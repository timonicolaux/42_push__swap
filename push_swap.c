/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:26:21 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/15 10:36:44 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char **str, int i)
{
	int	start;
	t_list	*a_lst;
	t_list	*b_lst;
	int	j;
	int	k;

	a_lst = NULL;
	b_lst = NULL;
	start = i;
	k = 0;
	while (str[i])
	{
		// while (str[i][k])
		// {
		// 	if ((str[i][k] < '0' && str[i][k] > '9') && (str[i][k] != '-'))
		// 		return (1);
		// 	k++;
		// }
		if (ft_atoi(str[i]) >= 2147483647 || ft_atoi(str[i]) <= -2147483648)
			return (1);
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[j]) == ft_atoi(str[i]))
				return (1);
			j++;
		}
		i++;
	}
	i = start;
	while (str[i])
	{
		ft_lstadd_back(&a_lst, ft_lstnew(ft_atoi(str[i])));
		i++;
	}
	algo(&a_lst, &b_lst);
	return (0);
}

int	main(int ac, char **av)
{
	char	**numbers;
	int		check_error;

	if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		// push_swap(ac, numbers, 0);
		check_error = push_swap(numbers, 0);
		if (check_error)
			printf("Error\n");
		free(numbers);
	}
	else if (ac > 2)
	{
		// push_swap(ac, av, 1);
		check_error = push_swap(av, 1);
		if (check_error)
			printf("Error\n");
	}
	else
		printf("Error\n");
	return (0);
}
