/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:27:58 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/15 14:17:37 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	int				number;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

int		push_swap(char **str, int i);
int		error_check(char **str, int i);
int		is_digit_check(char	*str);
void	algo(t_list **a_lst, t_list **b_lst);
void	three_numbers(t_list **lst);
void	four_numbers(t_list **a_lst, t_list **b_lst);

int		calculate_cost(int number, t_list **b_lst, int index, t_list **a_lst);
int		check_first_half(int number, t_list **b_lst, int index, t_list **a_lst);
int		check_second_half(int number, t_list **b_lst, int index,
			t_list **a_lst);

void	turk_algo(t_list **a_lst, t_list **b_lst);
void	first_move(t_list **a_lst, t_list **b_lst);
void	turk_algo_b(t_list **a_lst, t_list **b_lst);
void	turk_algo_a(t_list **a_lst, t_list **b_lst);

void	push_to_b(t_list **a_lst, t_list **b_lst, int index, int length);
void	first_a_half(t_list **a_lst, t_list **b_lst, int index);
void	second_a_half(t_list **a_lst, t_list **b_lst, int index, int length);
void	reorder_b_with_min(t_list **b_lst);
void	reorder_b_with_else(t_list **a_lst, t_list **b_lst);

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *first);
t_list	*lst_last(t_list **lst);
int		lst_length(t_list **lst);

int		find_min(t_list **lst);
int		find_max(t_list **lst);
int		find_num_with_index(t_list **lst, int index);
int		find_index_with_num(t_list **lst, int num);
int		is_sorted(t_list **lst);
int		find_closest_in_list(int num, t_list **lst);
int		find_closest_in_list2(int num, t_list **lst);
int		reorder_list_cost(t_list **lst);
int		check_double_move(int a_index, int b_index, t_list **a_lst,
			t_list **b_lst);

void	swap(t_list **first);
void	do_sa(t_list **lst);
void	do_sb(t_list **lst);
void	do_ss(t_list **a_stack, t_list **b_stack);
void	push(t_list **a_list, t_list **b_list);
void	do_pa(t_list **a_list, t_list **b_list);
void	do_pb(t_list **a_list, t_list **b_list);
void	rotate(t_list **first);
void	do_ra(t_list **lst);
void	do_rb(t_list **lst);
void	do_rr(t_list **a_list, t_list **b_list);
void	reverse(t_list **first);
void	do_rra(t_list **lst);
void	do_rrb(t_list **lst);
void	do_rrr(t_list **a_list, t_list **b_list);

#endif
