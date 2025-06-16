/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:50:31 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/06 20:13:54 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"\

//verifie si une carac est dans le set
static int	ft_inset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i ++;
	}
	return (0);
}

//lo ngueur totale de la chaine de depart
static int	ft_strlen_start(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

//retourne la longueur de la chaine trimée
static int	ft_strlentrim(char const *s, char const *set)
{
	int	count;
	int	fin;

	count = 0;
	fin = ft_strlen_start(s) - 1;
	while (ft_inset(s[count], set))
		count++;
	while (ft_inset(s[fin], set))
	{
		fin --;
		count++;
	}
	return (ft_strlen_start(s) - count);
}

static int	ft_countend(char const *s, char const *set)
{
	int	count;
	int	fin;

	count = 0;
	fin = ft_strlen_start(s) - 1;
	while (ft_inset(s[fin], set))
	{
		fin --;
		count++;
	}
	return (ft_strlen_start(s) - count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	int		i;
	int		j;
	int		countend;

	countend = ft_countend(s1, set);
	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (ft_inset(s1[i], set))
		i ++;
	if (i == ft_strlen_start(s1))
		copy = malloc(1 * sizeof(char));
	else
		copy = malloc(ft_strlentrim(s1, set) * sizeof(char) + 1);
	if (!copy)
		return (NULL);
	while ((i < countend))
		copy[j ++] = s1[i ++];
	copy[j] = '\0';
	return (copy);
}
/*int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%s\n", ft_strtrim(argv[1], argv[2]));
	}
}*/
