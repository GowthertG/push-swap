/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:21:04 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/06/25 04:24:57 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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

void	error(void)
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
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
						|| av[index[0]][index[1]] == '+'))
						&& ft_isdigit(av[index[0]][1]))
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
