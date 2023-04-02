/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:37:15 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/06/23 12:25:50 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int arc, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	chunk;
	int		*array;

	if (arc > 1)
	{
		stack_b = NULL;
		stack_a = fill_stack(av);
		check_stack(av);
		check_duplicate(av);
		if (!is_sorted(stack_a))
			return (1);
		array = sort_array(av, arc);
		if (ft_lstsize(stack_a) <= 15)
			small_sort(&stack_a, &stack_b);
		else if (ft_lstsize(stack_a) > 15)
			big_sort(&stack_a, &stack_b, &chunk, array);
	}
	return (0);
}
