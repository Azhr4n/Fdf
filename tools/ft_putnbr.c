/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/24 18:29:03 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/24 18:29:03 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "tools.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	if (n / 10 != 0)
	{
		if (n < 0)
			ft_putnbr(-(n / 10));
		else
			ft_putnbr(n / 10);
	}
	n %= 10;
	if (n < 0)
		n = -n;
	ft_putchar('0' + n);
}
