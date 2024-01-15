/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:41:35 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/15 13:58:18 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->number = content;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
	{
		(*lst)->previous = new;
		new->next = *lst;
		*lst = new;
		new->previous = NULL;
	}
	else
	{
		*lst = new;
		(*lst)->next = NULL;
		(*lst)->previous = NULL;
	}
}

void	ft_lstadd_back(t_list **first, t_list *second)
{
	t_list	*temp;

	if (!first || !second)
		return ;
	if (!(*first))
	{
		*first = second;
		(*first)->previous = NULL;
		(*first)->next = NULL;
		return ;
	}
	temp = *first;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = second;
	second->previous = temp;
}

t_list	*lst_last(t_list **lst)
{
	t_list	*lst_copy;

	if (!lst)
		return (NULL);
	lst_copy = *lst;
	while (lst_copy->next)
		lst_copy = lst_copy->next;
	return (lst_copy);
}

int	lst_length(t_list **lst)
{
	int		i;
	t_list	*lst_copy;

	if (!lst)
		return (0);
	else if (!(*lst)->next)
		return (1);
	i = 0;
	lst_copy = *lst;
	while (lst_copy)
	{
		lst_copy = lst_copy->next;
		i++;
	}
	return (i);
}
