/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/24 14:31:16 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/24 14:31:16 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "struct.h"
#include "my_mlx.h"
#include "tools.h"

static void	draw(t_settings *set, t_point *p1, t_point *p2)
{
	int		x;

	x = p1->x;
	while (x < p2->x)
	{
		if (p2->x - p1->x)
			print(set, x, p1->y + ((p2->y - p1->y)
				* (x - p1->x)) / (p2->x - p1->x));
		else
			print(set, x, 0);
		x++;
	}
}

static void	draw2(t_settings *set, t_point *p1, t_point *p2)
{
	int		y;

	y = p1->y;
	while (y < p2->y)
	{
		if (p2->y - p1->y)
			print(set, p1->x + ((p2->x - p1->x)
				* (y - p1->y)) / (p2->y - p1->y), y);
		else
			print(set, 0, y);
		y++;
	}
}

static void	settings_v(t_settings *set, t_point *p1, t_point *p2, int y)
{
	int		x;

	x = 0;
	while (x < set->map.size_line[y])
	{
		p1->y = y * set->mlx.step - set->map.map[y][x];
		p1->x = x * set->mlx.step - set->map.map[y][x];
		if (set->map.size_line[y + 1] >= set->map.size_line[y]
			|| x < set->map.size_line[y + 1])
		{
			p2->y = (y + 1) * set->mlx.step - set->map.map[y + 1][x];
			p2->x = x * set->mlx.step - set->map.map[y + 1][x];
		}
		else
		{
			p2->y = p1->y;
			p2->x = p1->x;
		}
		if (p1->y <= p2->y)
			draw2(set, p1, p2);
		else
			draw2(set, p2, p1);
		x++;
	}
}

static void	settings_verticals(t_settings *set)
{
	t_point	p;
	t_point	p1;
	t_point	p2;

	p.y = 0;
	while (p.y < set->map.nb_lines - 1)
	{
		settings_v(set, &p1, &p2, p.y);
		p.y++;
	}
	ft_putendl("Vertical lines setted !");
	free_struct(set);
}

void		setting_points(t_settings *set)
{
	t_point	p;
	t_point	p1;
	t_point	p2;

	p.y = 0;
	while (p.y < set->map.nb_lines)
	{
		p.x = 0;
		while (p.x < set->map.size_line[p.y] - 1)
		{
			p1.y = p.y * set->mlx.step - set->map.map[p.y][p.x];
			p1.x = p.x * set->mlx.step - set->map.map[p.y][p.x];
			p2.y = p.y * set->mlx.step - set->map.map[p.y][p.x + 1];
			p2.x = (p.x + 1) * set->mlx.step - set->map.map[p.y][p.x + 1];
			if (p1.x <= p2.x)
				draw(set, &p1, &p2);
			else
				draw(set, &p2, &p1);
			p.x++;
		}
		p.y++;
	}
	ft_putendl("Horizontal lines setted !");
	settings_verticals(set);
	ft_putendl("Printed !");
}
