/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:11:11 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/06/16 18:22:02 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_list *a, char instruction)
{
	t_list	*tmp;
	int		swp;

	tmp = a;
	tmp = tmp->next;
	swp = a->content;
	a->content = tmp->content;
	tmp->content = swp;
	if (instruction == 'a')
		write(1, "sa\n", 3);
	else if (instruction == 'b')
		write(1, "sb\n", 3);
}

void	push(t_list **donator, t_list **receiver, char instruction)
{
	t_list	*data;
	t_list	*leaks;

	leaks = *donator;
	data = NULL;
	if (*donator == NULL && instruction == 'b')
		exit (0);
	data = ft_lstnew((*donator)->content);
	ft_lstadd_front(receiver, data);
	*donator = (*donator)->next;
	if (instruction == 'a')
		write(1, "pa\n", 3);
	else if (instruction == 'b')
		write(1, "pb\n", 3);
	free(leaks);
}

void	ss(t_list **a, t_list **b)
{
	swap(*a, (char) NULL);
	swap(*b, (char) NULL);
	write(1, "ss\n", 3);
}

void	rotate(t_list **stack, char instruction)
{
	t_list	*tmp;
	t_list	*last;

	if (!ft_lstsize(*stack) || ft_lstsize(*stack) == 1)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = tmp;
	tmp->next = NULL;
	if (instruction == 'a')
		write(1, "ra\n", 3);
	else if (instruction == 'b')
		write(1, "rb\n", 3);
}
