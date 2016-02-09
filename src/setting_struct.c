/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/24 13:50:59 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/24 13:51:00 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

#include "main_functions.h"
#include "my_mlx.h"
#include "struct.h"
#include "my_mlx.h"
#include "tools.h"

static void	set_res(t_mlx *mlx, t_map *map)
{
	int		okay;

	okay = 0;
	mlx->step = 40;
	while (!okay)
	{
		mlx->width = map->longer_line * mlx->step + mlx->step
			+ (map->higher_value * 2);
		mlx->height = map->nb_lines * mlx->step + mlx->step
			+ (map->higher_value * 2);
		if (mlx->width > 2500 || mlx->height > 1400)
		{
			mlx->step -= 2;
			if (mlx->step < 1)
			{
				okay = 1;
				mlx->step = 1;
			}
		}
		else
			okay = 1;
	}
}

void		setting_struct(t_mlx *mlx, t_map *map, char *path)
{
	char	*str;

	str = parsing_file(path);
	setting_map(map, str);
	free(str);
	set_res(mlx, map);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height, TITLE);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	mlx->addr_data = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
		&mlx->size_line, &mlx->endian);
	mlx->color = mlx_get_color_value(mlx->mlx_ptr, 0xFFFFFF);
	ft_putendl("Struct setted !");
}
