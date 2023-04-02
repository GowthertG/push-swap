/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _big_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:05:52 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/06/25 03:33:02 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	catch_number(int num, int *array, t_data *chunk)
{
	if (num >= array[chunk->range[0]] && num <= array[chunk->range[1] - 1])
		return (EXIST);
	return (0);
}

void	get_range(t_data *chunk)
{
	static int	push_count = 1;

	if (chunk->size <= 150)
		chunk->chunk = chunk->size / 8;
	else
		chunk->chunk = chunk->size / 15;
	chunk->range[0] = chunk->mid_chunk - chunk->chunk * push_count;
	if (chunk->range[0] < 0)
		chunk->range[0] = 0;
	chunk->range[1] = chunk->mid_chunk + chunk->chunk * push_count;
	if (chunk->range[1] >= chunk->size)
		chunk->range[1] = chunk->size;
	push_count++;
	chunk->chunk_size = chunk->range[1] - chunk->range[0];
}

void	sub_sort(t_list **stack_a, t_list **stack_b, int *array, t_data *chunk)
{	
	if ((*stack_b)->content == array[chunk->index])
		(push(stack_b, stack_a, 'a'), chunk->index--);
	else
	{
		if (chunk->insorted == 0
			|| (*stack_b)->content > ft_lstlast(*stack_a)->content)
			(push(stack_b, stack_a, 'a'), rotate(stack_a, 'a'),
				chunk->insorted++);
		else
		{
			if (index_hunter(*stack_b, "bigger")
				< ft_lstsize(*stack_b) / 2)
				rotate(stack_b, 'b');
			else
				rrotate(stack_b, 'b');
		}
	}
}
