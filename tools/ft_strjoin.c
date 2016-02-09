/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/23 17:14:15 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/23 17:14:16 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tools.h"

char		*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc(sizeof(char)
		* (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (*s1)
	{
		new_str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		new_str[i] = *s2;
		s2++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
