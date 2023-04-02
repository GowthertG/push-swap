/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:17:54 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/06/24 02:29:57 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	main(int arc, char	**argv)
{
	t_list	*b;
	t_list	*a;
	char	*operation;

	if (arc > 1)
	{	
		a = NULL;
		b = NULL;
		operation = "Default";
		a = fill_stack(argv);
		(check_stack(argv), check_duplicate(argv));
		while (operation)
		{
			operation = get_next_line(0);
			if (operation)
				call_operation(operation, &a, &b);
			free(operation);
		}
		if (is_sorted(a) || ft_lstsize(b))
			return (write(1, "KO\n", 3));
		return (write(1, "OK\n", 3));
	}
}

int	is_sorted(t_list *stack)
{
	if (!stack)
		return (EXIT_FAILURE);
	while (stack->next)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	call_operation(char *operation, t_list **a, t_list **b)
{
	if (!ft_strcmp("sa\n", operation))
		swap(*a);
	else if (!ft_strcmp("sb\n", operation))
		swap(*b);
	else if (!ft_strcmp("ss\n", operation))
		ss(a, b);
	else if (!ft_strcmp("pb\n", operation))
		push(a, b);
	else if (!ft_strcmp("pa\n", operation))
		push(b, a);
	else if (!ft_strcmp("ra\n", operation))
		rotate(a);
	else if (!ft_strcmp("rb\n", operation))
		rotate(b);
	else if (!ft_strcmp("rr\n", operation))
		rr(a, b);
	else if (!ft_strcmp("rra\n", operation))
		rrotate(a);
	else if (!ft_strcmp("rrb\n", operation))
		rrotate(b);
	else if (!ft_strcmp("rrr\n", operation))
		rrr(a, b);
	else
		exit(write(2, "Error\n", 7));
}
