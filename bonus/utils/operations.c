/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:11:11 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/06/23 20:22:28 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"
#include <stdio.h>

void	swap(t_list *a)
{
	t_list	*tmp;
	int		swp;

	if ((ft_lstsize(a)) < 2)
		return ;
	tmp = a;
	tmp = tmp->next;
	swp = a->content;
	a->content = tmp->content;
	tmp->content = swp;
}

void	push(t_list **donator, t_list **receiver)
{
	t_list	*data;
	t_list	*leaks;

	if (!(ft_lstsize(*donator)))
		return ;
	leaks = *donator;
	data = NULL;
	data = ft_lstnew((*donator)->content);
	ft_lstadd_front(receiver, data);
	*donator = (*donator)->next;
	free(leaks);
}

void	ss(t_list **a, t_list **b)
{
	swap(*a);
	swap(*b);
}

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = tmp;
	tmp->next = NULL;
}
