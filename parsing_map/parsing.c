/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:09:02 by mlemee            #+#    #+#             */
/*   Updated: 2025/06/16 21:31:56 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include "parsing.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_count_line(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	ft_check_first_n_last(char **split, int nlines)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (split[0][i])
	{
		if (split[0][i] != '1')
			return (0);
		i++;
	}
	while (split[nlines - 1][j])
	{
		if (split[nlines - 1][j] != '1')
			return (0);
		j++;
	}
	if (j != i)
		return (0);
	return (i);
}

int	ft_check_columns(char **split)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(split[i]) - 1;
	while (split[i])
	{
		if (split[i][0] != '1')
		{
			printf("ERREUR COLONNE INDEX I = %d et char = %c\n", i, split[i][0]);
			return (0);
		}
		i++;
	}
	i = 1;
	while (split[i])
	{
		if (split[i][len] != '1')
		{
			printf("ERREUR COLONNE INDEX I = %d, char index == %d et char = %c\n", i, len, split[i][len]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_len(char **split)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(split[i]);
	i++;
	while (split[i])
	{
		if (len != ft_strlen(split[i]))
			return (0);
		i++;
	}
	return (len);
}

char	*ft_read(char *filename)
{
	int		fd;
	char	*line;
	char	*content;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = ft_strdup("");
	while ((line = get_next_line(fd)))
	{
		// ft_printf("Reading line: %s", line);  // Debug print
		temp = content;
		content = ft_strjoin(content, line);
		free(temp);
		free(line);
	}
	close(fd);
	return (content);
}

char	**ft_parse(char *filename)
{
	char	**split;
	char	*line;
	int		nlines;

	line = ft_read(filename);
	if (!line)
		return (NULL);
	split = ft_split(line, '\n');
	if (!split)
		exit (0);
	nlines = ft_count_line(split);
	if (nlines <= 2) //si moins de 2 lignes map invalide
		return (ft_printf("Error NLINES %d\n", nlines),ft_free_split(split), free(line), exit (0), NULL);
	if (!ft_check_first_n_last(split, nlines)) //check premiere et derniere ligne aue des 1
		return (ft_printf("Error 2\n"),ft_free_split(split), free(line), exit (0), NULL);
	if (ft_check_len(split) <= 2) //check la longueur de chaque string
		return (ft_printf("Error CHECK LEN\n"),ft_free_split(split), free(line), exit (0), NULL);
	if (!ft_check_columns(split)) //check si chaque ligne commence et fini par 1
		return (ft_printf("Error CHECK COLUMNS\n"),ft_free_split(split), free(line), exit (0), NULL);
	if (!ft_check_pce(line)) //check si bien 1 player 1 exit et au moins plus de 1 collectibles 
		return (ft_printf("Error CHECK PCE\n"),ft_free_split(split), free(line), exit (0), NULL);
	if (!ft_check_zero(line)) //check bien sil ny a que des carac valides dans le .ber
		return (ft_printf("Error CHECK 0\n"), ft_free_split(split), free(line),exit (0), NULL);
	return (free(line), split);
}
