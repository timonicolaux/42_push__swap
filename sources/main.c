/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:26:21 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/19 09:16:15 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char **str, int i)
{
	t_list	*a_lst;
	t_list	*b_lst;
	t_list	*new_lst;

	a_lst = NULL;
	b_lst = NULL;
	new_lst = NULL;
	if (error_check(str, i))
		return (1);
	while (str[i])
	{
		new_lst = ft_lstnew(ft_atoi(str[i]));
		if (!new_lst)
			break ;
		ft_lstadd_back(&a_lst, new_lst);
		i++;
	}
	if (lst_length(&a_lst) > 1 && !is_sorted(&a_lst) && new_lst)
		algo(&a_lst, &b_lst);
	clear_lst(&a_lst);
	clear_lst(&b_lst);
	return (0);
}

int	error_check(char **str, int i)
{
	int	j;

	while (str[i])
	{
		if (is_digit_check(str[i]))
			return (1);
		if ((ft_atoi(str[i]) == 0 && str[i][0] != '0' && str[i][0] != '+'
		&& str[i][0] != '-') || (ft_atoi(str[i]) == 0 && (str[i][0] == '+'
		|| str[i][0] == '-') && str[i][1] != '0'))
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
	return (0);
}

int	is_digit_check(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (1);
		if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		{
			if (!ft_isdigit(str[i + 1]))
				return (1);
		}
		if ((str[i] == '-' || str[i] == '+') && str[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

int	main(int ac, char **av)
{
	char	**numbers;
	int		check_error;

	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		check_error = push_swap(numbers, 0);
		if (check_error)
			write(2, "Error\n", 6);
		free_split(numbers);
	}
	else if (ac > 2)
	{
		check_error = push_swap(av, 1);
		if (check_error)
			write(2, "Error\n", 6);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
