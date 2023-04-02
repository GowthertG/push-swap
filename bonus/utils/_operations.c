/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:17:07 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/06/23 20:22:51 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}

void	rrotate(t_list **stack)
{
	t_list	*t;

	if (ft_lstsize(*stack) < 2)
		return ;
	t = *stack;
	while (t->next->next)
		t = t->next;
	ft_lstadd_front(stack, t->next);
	t->next = NULL;
}

void	rrr(t_list **a, t_list **b)
{
	rrotate(a);
	rrotate(b);
}
