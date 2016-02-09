/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/23 16:05:11 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/23 16:05:14 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "struct.h"

void		ft_putendl(char *str);
void		ft_putstr(char *str);
void		clean(char *tab, int size);
void		ft_putnbr(int n);
void		free_struct(t_settings *set);

int			ft_strlen(char *str);
int			short_atoi(char *str);

char		*ft_strjoin(char *s1, char *s2);

#endif
