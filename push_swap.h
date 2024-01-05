/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:27:58 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/05 11:11:20 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				number;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

int	ft_atoi(char *nptr);
char	**ft_split(char *s, char c);
size_t	ft_strlen(char *str);

int		push_swap(int ac, char **str, int i);
void	algo(t_list **a_lst, t_list **b_lst);
void	three_numbers(t_list **lst);
void	four_five_numbers(t_list **a_lst, t_list **b_lst, int length);

t_list	*ft_lstnew(int	content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *first);
t_list	*lst_last(t_list **lst);
int		lst_length(t_list **lst);

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
