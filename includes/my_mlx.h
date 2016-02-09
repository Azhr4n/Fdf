/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/24 13:56:51 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/24 13:56:51 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H
# define MY_MLX_H

# include "struct.h"

# define TITLE "Iron string"
# define ESC 65307
# define ABS(x) x < 0 ? (-x) : x

# define A (y - set->map.nb_lines * set->mlx.step / 2)
# define B (A + set->mlx.height / 2)
# define C (x - set->map.longer_line * set->mlx.step / 2)
# define D (set->mlx.bpp / 8)
# define E B * set->mlx.size_line
# define F E + (C + set->mlx.width / 2) * D

void		setting_struct(t_mlx *mlx, t_map *map, char *path);
void		setting_points(t_settings *set);
void		print(t_settings *set, int x, int y);

int			mlx_key(int keycode, void *param);

#endif
