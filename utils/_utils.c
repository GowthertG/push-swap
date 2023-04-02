/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:07:00 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/06/23 08:06:23 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fill_array(char	**av,	int *array)
{
	int	index;

	index = 0;
	while (av[index + 1])
	{
		array[index] = ft_atoi(av[index + 1]);
		index++;
	}	
}

void	bubble_sort(int *array, int size)
{
	int	index[2];
	int	tmp;

	index[0] = 0;
	while (index[0] < size)
	{
		index[1] = 0;
		while (index[1] < size - 1)
		{
			if (array[index[1]] > array[index[1] + 1])
			{
				tmp = array[index[1]];
				array[index[1]] = array[index[1] + 1];
				array[index[1] + 1] = tmp;
			}
			index[1]++;
		}
		index[0]++;
	}
}

void	error(void)
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}
