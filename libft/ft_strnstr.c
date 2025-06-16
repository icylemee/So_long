/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:17:16 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/06 17:51:31 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (((i + j) < len) && (big[i + j] == little[j]))
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i ++;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
	if (argc == 4)
	{
		if (ft_strnstr(argv[1], argv[2], atoi(argv[3])) == NULL)
		{
			printf("Erreur");
			return 0;
		}
		printf("%s\n", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
		//printf("%s\n", strnstr(argv[1], argv[2], atoi(argv[3])));
	}
}*/
