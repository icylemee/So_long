/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:46:41 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/06 16:24:51 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i ++;
	}
	return (0);
}

/*int main(int argc, char *argv[])
{
	if (argc == 4)
	{
printf("ma fonction : %d\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
		printf("originale : %d\n", strncmp(argv[1], argv[2], atoi(argv[3])));
	}
}*/

/*int main()
{
	char *s1 = "the cake is a lie !\0I'm hidden lol\r\n";
	char *s2 = "there is no stars in the sky";
	size_t size = strlen("the cake is a lie !\0I'm hidden lol\r\n");
	printf("ma fonction : %d\n", ft_strncmp(s1, s2, size));
	printf("originale : %d\n", strncmp(s1, s2, size));
}*/
