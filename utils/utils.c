/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:37:02 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/06/23 11:27:18 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*fill_stack(char	**arv)
{
	int		i;
	t_list	*new;
	t_list	*list;

	i = 1;
	new = NULL;
	list = NULL;
	while (arv[i])
	{
		new = ft_lstnew(ft_atoi(arv[i]));
		if (!new)
			exit(1);
		ft_lstadd_back(&list, new);
		i++;
	}
	return (list);
}

void	check_stack(char **av)
{
	int	index[2];

	index[0] = 1;
	while (av[index[0]])
	{
		index[1] = 0;
		while (av [index[0]][index[1]])
		{
			if (!ft_isdigit(av[index[0]][index[1]]))
			{
				if ((!(index[1]) && (av[index[0]][index[1]] == '-'
						|| av[index[0]][index[1]] == '+')
					&& ft_isdigit(av[index[0]][1])))
					index[1]++;
				else
					error();
			}
			index[1]++;
		}
		index[0]++;
	}
}

void	check_duplicate(char **av)
{
	int	index;
	int	index2;

	index = 1;
	while (av[index])
	{
		index2 = index + 1;
		while (av[index2])
		{
			if (ft_atoi(av[index]) == ft_atoi(av[index2]))
				error();
			index2++;
		}
		index++;
	}
}

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	*sort_array(char **av, int ac)
{	
	int	*array;

	array = (int *) malloc ((ac - 1) * sizeof(int));
	fill_array(av, array);
	bubble_sort(array, ac - 1);
	return (array);
}
