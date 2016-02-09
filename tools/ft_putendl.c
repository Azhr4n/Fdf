/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/23 16:09:41 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/23 16:09:42 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "tools.h"

void		ft_putendl(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
