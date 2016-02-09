/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/23 18:39:01 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/23 18:39:01 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "main_functions.h"
#include "struct.h"
#include "tools.h"

static int	check_buffer(char *buffer, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (buffer[i])
			return (0);
		i++;
	}
	return (1);
}

int			size_line(char *str)
{
	int		count;
	int		flag;

	count = 0;
	flag = 0;
	while (*str && *str != '\n')
	{
		if (!flag && *str >= '0' && *str <= '9')
		{
			count++;
			flag = 1;
		}
		if (*str < '0' || *str > '9')
			flag = 0;
		str++;
	}
	return (count);
}

int			nb_lines(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (*str == '\n')
			count++;
		str++;
	}
	return (count);
}

char		*parsing_file(char *path)
{
	char	buffer[BUFFSIZE + 1];
	char	*tmp;
	char	*str;
	int		fd;

	clean(buffer, BUFFSIZE + 1);
	fd = open(path, O_RDONLY);
	str = (char *)malloc(sizeof(char) * 1);
	while (read(fd, buffer, BUFFSIZE))
	{
		tmp = str;
		str = ft_strjoin(tmp, buffer);
		if (check_buffer(buffer, BUFFSIZE))
			exit(0);
		clean(buffer, BUFFSIZE + 1);
		free(tmp);
	}
	close(fd);
	return (str);
}
