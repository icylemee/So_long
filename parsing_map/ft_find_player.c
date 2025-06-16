/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:33:11 by mlemee            #+#    #+#             */
/*   Updated: 2025/06/13 21:58:19 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

int	ft_find_player_y(char **split)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (split[i])
	{
		while (split[i][y])
		{
			if (split[i][y] == 'P')
				return (y);
			y ++;
		}
		y = 0;
		i ++;
	}
	return (0);
}

int	ft_find_player_x(char **split)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (split[x])
	{
		while (split[x][y])
		{
			if (split[x][y] == 'P')
				return (x);
			y ++;
		}
		y = 0;
		x++;
	}
	return (0);
}
