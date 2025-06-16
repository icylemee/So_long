/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:22:01 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/05 15:28:28 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (i < (n - 1) && src[i])
	{
		dest[i] = src[i];
		i ++;
	}
	if (n > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}
/*#include <stdio.h>
#include <bsd/string.h>
int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		char dest[100];
		//printf("%zu\n%s\n", strlcpy(dest, argv[1], ft_atoi(argv[2])), dest);
		printf("%lu\n%s\n", ft_strlcpy(dest, argv[1], ft_atoi(argv[2])), dest);
	}
}*/
