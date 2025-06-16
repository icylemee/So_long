/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:32:40 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/05 13:53:18 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

/*static int	ft_strlen_join(const char *s)
{
	int	i; 

	i = 0;
	while (s[i])
		i++;
	return (i);
}*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lt;
	char	*new;
	int		i;
	int		j;

	lt = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(lt * sizeof(char));
	if (new == NULL)
		return (new);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i ++;
	}
	j = 0;
	while (s2[j])
	{
		new[i] = s2[j];
		i ++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

/*int main(int argc, char *argv[])
{
	if(argc == 3)
	{
		printf("%s\n", ft_strjoin(argv[1], argv[2]));
	}
}*/
