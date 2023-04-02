/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:07:38 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/06/23 20:23:04 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	if (!ft_strlen((char *)str))
		error();
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		check_mn((unsigned long)res * 10 + (*str - 48), sign);
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}

void	check_mn(unsigned long value, int sign)
{
	if (value > 2147483647 && sign == 1)
		error();
	else if (value > (unsigned long)2147483647 + 1 && sign == -1)
		error();
}
