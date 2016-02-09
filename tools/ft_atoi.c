/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/23 18:58:55 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/23 18:58:56 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static int	ft_mul(char *str)
{
	int		mul;

	mul = 1;
	while (*str && *str >= '0' && *str <= '9')
	{
		mul *= 10;
		str++;
	}
	return (mul / 10);
}

int			short_atoi(char *str)
{
	int		result;
	int		mul;
	int		neg;

	neg = 0;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	result = 0;
	mul = ft_mul(str);
	while (*str && *str >= '0' && *str <= '9')
	{
		result += (*str - '0') * mul;
		mul /= 10;
		str++;
	}
	if (neg)
		return (-result);
	return (result);
}
