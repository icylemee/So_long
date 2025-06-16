/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:44:50 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/05 17:58:55 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_cat(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	t;
	int		j;

	i = 0;
	j = 0;
	t = 0;
	if ((size_t)ft_strlen(dest) >= n)
		return (n + ft_strlen(src));
	while (dest[i])
		i++;
	t = i;
	while (i < (n - 1) && src[j])
	{
		dest[i] = src[j];
		i ++;
		j ++;
	}
	if (i < n)
		dest[i] = '\0';
	return (t + ft_strlen_cat(src));
}

/*#include <bsd/string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		char dest[100] = "Hello ";
		//printf("%ld\n%s\n", strlcat(dest, argv[1], ft_atoi(argv[2])), dest);
		printf("%ld\n%s\n", ft_strlcat(dest, argv[1], ft_atoi(argv[2])), dest);
	}
}*/