/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:50:27 by mlemee            #+#    #+#             */
/*   Updated: 2025/06/16 17:45:24 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lt;
	char	*new;
	int		i;
	int		j;

	if (!s2)  // Protection against NULL s2
        return (NULL);
	lt = ft_strlengnl(s1) + ft_strlengnl(s2) + 1;
	new = malloc(lt * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	if (s1 != NULL)
	{
		while (s1[i])
		{
			new[i] = s1[i];
			i ++;
		}
	}
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

ssize_t	ft_strlengnl(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchrgnl(char *s, char c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
