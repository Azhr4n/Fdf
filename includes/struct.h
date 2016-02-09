/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/23 15:36:08 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/23 15:36:09 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef	struct		s_map
{
	int				nb_lines;
	int				longer_line;
	int				higher_value;
	int				*size_line;
	int				**map;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*addr_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				color;
	int				width;
	int				height;
	int				step;
}					t_mlx;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_settings
{
	t_map			map;
	t_mlx			mlx;
}					t_settings;

#endif
