/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _operations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:17:07 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/06/25 06:50:58 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rr(t_list **a, t_list **b)
{
	rotate(a, (char) NULL);
	rotate(b, (char) NULL);
	write(1, "rr\n", 3);
}

void	rrotate(t_list **stack, char instruction)
{
	t_list	*t;

	if (ft_lstsize(*stack) < 2)
		return ;
	t = *stack;
	while (t->next->next)
		t = t->next;
	ft_lstadd_front(stack, t->next);
	t->next = NULL;
	if (instruction == 'a')
		write(1, "rra\n", 4);
	else if (instruction == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rrotate(a, 'a');
	rrotate(b, 'b');
}
