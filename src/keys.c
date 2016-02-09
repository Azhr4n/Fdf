/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/24 13:54:48 by pivanovi          #+#    #+#             */
/*   Updated: 2014/09/24 13:54:49 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "my_mlx.h"

int			mlx_key(int keycode, void *param)
{
	(void)param;
	if (keycode == ESC)
		exit(0);
	return (0);
}
