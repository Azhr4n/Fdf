/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/23 15:39:51 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/23 15:39:52 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "main_functions.h"
#include "my_mlx.h"
#include "struct.h"
#include "tools.h"

static void	text(t_map *map)
{
	ft_putendl("Map parsed !");
	ft_putstr("Nb lines : ");
	ft_putnbr(map->nb_lines);
	ft_putstr("\n");
	ft_putstr("Size of longer line : ");
	ft_putnbr(map->longer_line);
	ft_putstr("\n");
	ft_putstr("Higher value : ");
	ft_putnbr(map->higher_value);
	ft_putstr("\n");
}

static void	setting_m(t_map *map, char **str, int i)
{
	int		j;
	int		tmp;

	j = -1;
	while (++j < map->size_line[i])
	{
		if ((**str >= '0' && **str <= '9')
			|| (**str == '-' && *(*str + 1) >= '0' && *(*str + 1) <= '9'))
		{
			map->map[i][j] = short_atoi(*str);
			tmp = ABS(map->map[i][j]);
			if (map->higher_value < tmp)
				map->higher_value = tmp;
			while ((**str >= '0' && **str <= '9') || **str == '-')
				(*str)++;
		}
		while ((**str == ' ' || **str == '\n') && **str)
			(*str)++;
	}
}

void		setting_map(t_map *map, char *str)
{
	int		i;

	i = -1;
	map->nb_lines = nb_lines(str);
	map->longer_line = 0;
	map->higher_value = 0;
	map->size_line = (int *)malloc(sizeof(int) * (map->nb_lines));
	map->map = (int **)malloc(sizeof(int *) * (map->nb_lines));
	while (++i < map->nb_lines)
	{
		map->size_line[i] = size_line(str);
		if (map->longer_line < map->size_line[i])
			map->longer_line = map->size_line[i];
		map->map[i] = (int *)malloc(sizeof(int) * (map->size_line[i]));
		setting_m(map, &str, i);
	}
	text(map);
}
