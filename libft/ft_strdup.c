/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:17:06 by mlemee            #+#    #+#             */
/*   Updated: 2025/06/16 20:19:19 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

static int	ft_strlen_dup(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i + 1);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*copy;

	i = 0;
	copy = malloc(ft_strlen_dup(s) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i ++;
	}
	copy[i] = '\0';
	return (copy);
}

/*int main (int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%s\n", ft_strdup(argv[1]));
		
	}
}*/