/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/24 17:27:04 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/24 17:27:04 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "my_mlx.h"

void		print(t_settings *set, int x, int y)
{
	set->mlx.addr_data[F] = (set->mlx.color & 0xFF0000) >> 16;
	set->mlx.addr_data[F + 1] = (set->mlx.color & 0xFF00) >> 8;
	set->mlx.addr_data[F + 2] = (set->mlx.color & 0xFF) >> 0;
}
