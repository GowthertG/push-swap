/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:10:44 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/06/25 05:27:09 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

void	small_sort(t_list **a, t_list **b)
{
	if (ft_lstsize((*a)) == 2)
		sort_two(a);
	else if (ft_lstsize((*a)) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) >= 3)
		sort_fifteen(a, b);
}

int	index_hunter(t_list *stack, char *target)
{
	int	claimer;
	int	index;
	int	target_index;

	index = 0;
	target_index = 0;
	claimer = stack->content;
	while (stack)
	{
		if ((!ft_strcmp(target, "bigger")) && claimer < stack->content)
		{
			claimer = stack->content;
			target_index = index;
		}
		else if (!ft_strcmp(target, "smaller") && stack->content < claimer)
		{
			claimer = stack->content;
			target_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (target_index);
}

void	sort_two(t_list	**a)
{
	if (!is_sorted(*a))
		return ;
	swap(*a, 'a');
}

void	sort_three(t_list **a)
{
	if (index_hunter(*a, "bigger") == 1)
		rrotate(a, 'a');
	else if (index_hunter(*a, "bigger") == 0)
		rotate(a, 'a');
	sort_two(a);
}

void	sort_fifteen(t_list **stack_a, t_list **stack_b)
{
	if (!is_sorted(*stack_a))
		exit(1);
	while (ft_lstsize(*stack_a) > 3)
	{
		if (index_hunter(*stack_a, "smaller") == 0)
			push(stack_a, stack_b, 'b');
		else if (index_hunter(*stack_a, "smaller") < (ft_lstsize(*stack_a) / 2))
			rotate(stack_a, 'a');
		else
			rrotate(stack_a, 'a');
	}
	sort_three(stack_a);
	while (ft_lstsize(*stack_b))
		push(stack_b, stack_a, 'a');
}
