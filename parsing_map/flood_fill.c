/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:16:27 by mlemee            #+#    #+#             */
/*   Updated: 2025/06/16 20:54:48 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include <stdio.h>

char	**ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}

int	ft_case_valide(char c, int *countcpe)
{
	if (c == '0')
		return (1);
	if (c == 'C')
	{
		countcpe[0]++;
		return (1);
	}
	if (c == 'P')
	{
		countcpe[1]++;
		return (1);
	}
	if (c == 'E')
	{
		countcpe[2]++;
		return (1);
	}
	return (0);
}

void	ft_verif_split(char **split)
{
	if (!split)
	{
		ft_printf("Error\n");
		ft_free_split(split);
		exit (0);
	}
}

void	flood_fill(char **copymap, int x, int y, int *countcpe)
{
	if (!copymap[x][y] || x > ft_count_line(copymap)
		|| y > ft_strlen((const char *)copymap[0]))
		return ;
	if (!ft_case_valide(copymap[x][y], countcpe))
		return ;
	copymap[x][y] = 'V';
	flood_fill(copymap, x, y + 1, countcpe);
	flood_fill(copymap, x, y - 1, countcpe);
	flood_fill(copymap, x + 1, y, countcpe);
	flood_fill(copymap, x - 1, y, countcpe);
}

char	**parse_ff(char **split, int x, int y, char *filename)
{
	char	**copymap;
	int		i;
	int		countcpe[3] = {0, 0, 0};
	char	*line;

	line = ft_read(filename);
	if (!line)
		return (NULL);
	i = 0;
	ft_verif_split(split);
	copymap = malloc(sizeof(char *) * (ft_count_line(split) + 1));
	if (!copymap)
	{
		ft_free_split(split);
		exit (0);
	}
	while (i < ft_count_line(split))
	{
		copymap[i] = ft_strdup(split[i]);
		if (!copymap[i])
			return (NULL);
		i++;
	}
	copymap[i] = NULL;
	flood_fill(copymap, x, y, countcpe);
	if (countcpe[0] != ft_check_pce(line) || countcpe[1] != 1
		|| countcpe[2] != 1)
	{
		ft_free_split(split);
		ft_free_split(copymap);
		free(line);
		// printf("FONCTION COUNT C = %d; COUNTC = %d\n", ft_check_pce(line),countcpe[0]);
		// printf("COUNTP = %d\n",countcpe[1]);
		// printf("COUNTE = %d\n",countcpe[2]);
		// ft_printf("Error\nProbleme au niveau des collectibles/Exit et/ou Player\n");
		exit (0);
	}
	return (ft_free_split(copymap), free(line), split);
}
