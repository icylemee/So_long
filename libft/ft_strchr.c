/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:49:01 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/06 17:06:23 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
/*char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}*/

/*int main(int argc, char *argv[])
{

	//char *test = NULL;
	//const char *src = "Salut";
	//int c = 'l';

	printf("%s\n", ft_strchr(src, c));

	if (argc == 3)
	{
		char *test = ft_strchr(argv[1], atoi(argv[2]));
		if (test == NULL)
		{
			printf("Occurence non trouvée\n");
			return (0);
		}
		printf("Occurence trouvée : %s\n", test);
		return (0);
	}
}*/