/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:32:45 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/06/25 06:18:13 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	big_sort(t_list **stack_a, t_list **stack_b, t_data *chunk, int *array)
{
	init_data(stack_a, chunk);
	push_chunk(chunk, array, stack_a, stack_b);
	sort_chunks(stack_a, stack_b, array, chunk);
}

void	init_data(t_list **stack_a, t_data *chunk)
{
		chunk->size = ft_lstsize(*stack_a);
		chunk->mid_chunk = chunk->size / 2;
		chunk->chunk_size = chunk->chunk_index[1] - chunk->chunk_index[0];
}

void	sort_chunks(t_list **stack_a, t_list **stack_b,
	int *array, t_data *chunk)
{
	chunk->index = chunk->size - 1;
	chunk->insorted = 0;
	while (*stack_b && chunk->index > -1)
	{
		if (exist(array[chunk->index], stack_b))
			sub_sort(stack_a, stack_b, array, chunk);
		else
		{
			rrotate(stack_a, 'a');
			chunk->insorted--;
			chunk->index--;
		}
	}
	while (chunk->insorted)
		(rrotate(stack_a, 'a'), chunk->insorted--);
}

int	exist(int bigger, t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->content == bigger)
			return (EXIST);
		tmp = tmp->next;
	}
	return (FALSE);
}

void	push_chunk(t_data *chunk, int *array,
			t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a))
	{
		get_range(chunk);
		while (ft_lstsize(*stack_b) < chunk->chunk_size)
		{
			if (catch_number((*stack_a)->content, array, chunk) == EXIST)
			{
				push(stack_a, stack_b, 'b');
				if ((*stack_b)->content < array[chunk->mid_chunk])
					rotate(stack_b, 'b');
			}
			else
				rotate(stack_a, 'a');
		}
	}
}
