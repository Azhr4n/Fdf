/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/23 16:06:42 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/23 16:06:42 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_FUNCTIONS_H
# define MAIN_FUNCTIONS_H

# include "struct.h"

# define PATH "map/mars-200.fdf"
# define BUFFSIZE 1024

char		*parsing_file(char *path);

int			size_line(char *str);
int			nb_lines(char *str);

void		setting_map(t_map *map, char *str);

#endif
