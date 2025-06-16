/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:30:09 by mlemee            #+#    #+#             */
/*   Updated: 2025/06/16 17:24:26 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_sta(char *sta, int fd)
{
	ssize_t	endbuf;
	char	*buf;
	char	*tmp;

	endbuf = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (free(sta), NULL);
	while (ft_strchrgnl(sta, '\n') == 0 && endbuf != 0)
	{
		endbuf = read(fd, buf, BUFFER_SIZE);
		if (endbuf < 0)
			return (free(buf), free(sta), sta = NULL, NULL);
		buf[endbuf] = '\0';
		tmp = ft_strjoin(sta, buf);
		if (!tmp)
			return (free(buf), free(sta), sta = NULL, NULL);
		free(sta);
		sta = tmp;
	}
	free(buf);
	return (sta);
}

char	*ft_fill_line(char *sta)
{
	char	*line;
	int		i;

	i = 0;
	if (!sta || !sta[0])
		return (NULL);
	while (sta[i] != '\n' && sta[i])
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (sta[i] && sta[i] != '\n')
	{
		line[i] = sta[i];
		i++;
	}
	if (sta[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_sta(char *sta)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (sta[i] && sta[i] != '\n')
		i++;
	if (sta[i] == '\0')
		return (free(sta), sta = NULL, NULL);
	i++;
	if (!sta[i])
		return (free(sta), sta = NULL, NULL);
	new = malloc(sizeof(char) * (ft_strlengnl(&sta[i]) + 1));
	if (!new)
		return (free(sta), sta = NULL, NULL);
	while (sta[i])
		new[j++] = sta[i++];
	new[j] = '\0';
	free(sta);
	sta = NULL;
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*sta = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(sta);
		sta = NULL;
		return (NULL);
	}
	sta = ft_fill_sta(sta, fd);
	if (!sta)
		return (NULL);
	line = ft_fill_line(sta);
	if (line == NULL)
	{
		free(sta);
		sta = NULL;
		return (NULL);
	}
	sta = ft_new_sta(sta);
	return (line);
}

/*#include <stdio.h>
int	main(void)
{
    int		fd;
    char	*line;

    fd = open("test2.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Erreur fichier\n");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    line = get_next_line(-1);
    if (line)
	{
		 free(line);
	}
	get_next_line(-2);
    return (0);
}*/

/*#include <stdio.h>
int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	
	char *s = get_next_line(fd);
	while (s)
	{
   	 printf("%s", s);
   	 free(s);
   	 s = get_next_line(fd);
	}
	free(s);
	close(fd);
	return (0);
}*/
/*char	*ft_new_sta(char *sta, char *line)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (sta[i] != '\n' && sta[i])
		i++;
	if (sta[i] == '\0')
	{
		line[ft_strlen(line)] = '\0';
		free(sta);
		return (sta = NULL, NULL);
	}
	else
		new = malloc(sizeof(char) * (ft_strlen(sta) + 1 - i));
	if (!new)
	{
		free(sta);
		free(line);
		return (NULL);
	}
	i++;
	while (sta[i])
		new[j++] = sta[i++];
	new[j] = '\0';
	free(sta);
	sta = NULL;
	return (new);
}*/