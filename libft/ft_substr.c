/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:40:06 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/06 16:54:22 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_empty_string(void)
{
	char	*new;

	new = malloc(1);
	if (!new)
		return (NULL);
	new[0] = '\0';
	return (new);
}

static size_t	ft_min_size(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	slen;
	size_t	new_len;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_empty_string());
	new_len = ft_min_size(len, slen - start);
	new = malloc(new_len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < new_len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		printf("%s\n", ft_substr(argv[1], atoi(argv[2]), atoi(argv[3])));
	}
}*/