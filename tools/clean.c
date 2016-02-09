/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/23 16:01:12 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/23 16:01:12 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "struct.h"
#include "tools.h"

void		free_struct(t_settings *set)
{
	int		i;

	i = 0;
	while (i < set->map.nb_lines)
	{
		free(set->map.map[i]);
		i++;
	}
	free(set->map.map);
	free(set->map.size_line);
	ft_putendl("Struct freed !");
}

void		clean(char *tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
}
