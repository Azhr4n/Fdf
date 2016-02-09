/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/23 16:03:39 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/23 16:03:39 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "main_functions.h"
#include "my_mlx.h"
#include "struct.h"
#include "tools.h"

static int	reprint(t_settings *set)
{
	mlx_put_image_to_window(set->mlx.mlx_ptr, set->mlx.win_ptr,
		set->mlx.img_ptr, 0, 0);
	return (0);
}

int			main(int ac, char **av)
{
	t_settings	set;

	if (ac == 2)
	{
		setting_struct(&set.mlx, &set.map, av[1]);
		setting_points(&set);
		mlx_key_hook(set.mlx.win_ptr, mlx_key, 0);
		mlx_expose_hook(set.mlx.win_ptr, reprint, &set);
		mlx_loop(set.mlx.mlx_ptr);
	}
	return (0);
}
