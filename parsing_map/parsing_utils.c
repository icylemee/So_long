/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:21:28 by mlemee            #+#    #+#             */
/*   Updated: 2025/06/16 20:57:12 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include <stdio.h>

int	ft_check_pce(char *filename)
{
	int	i;
	int	e;
	int	p;
	int	c;

	i = 0;
	e = 0;
	p = 0;
	c = 0;
	while (filename[i])
	{
		if (filename[i] == 'E')
			e ++;
		if (filename[i] == 'P')
			p ++;
		if (filename[i] == 'C')
			c ++;
		i++;
	}
	if (e != 1 || p != 1 || c < 1)
		return (0);
	return (printf("\nC IN CHECK PCE RETURN = %d\n", c), c);
}

int	ft_check_zero(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] != 'C' && filename[i] != '0' && filename[i] != 'P'
			&& filename[i] != 'E' && filename[i] != '1' && filename[i] != '\n')
			{
				// printf("ERREUR CHECK CHARAC A INDEX = %d et CHARAC = %c\n", i, filename[i]);
				return (0);
			}
		i ++;
	}
	return (1);
}
