/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:26:06 by mlemee            #+#    #+#             */
/*   Updated: 2025/06/16 20:46:00 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	**s;

	s = ft_parse("parsing_map/maps/map.ber");
	if (!s)
		return (0);
	if (!parse_ff(s, ft_find_player_x(s), ft_find_player_y(s), "parsing_map/maps/map.ber"))
	{
		printf("ERREUR PARSE\n");
	}
	else
	{
		printf("MAP VALIDE\n");
	}
	return (ft_free_split(s), 0);
}
