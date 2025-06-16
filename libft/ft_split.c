/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:25:19 by mlemee            #+#    #+#             */
/*   Updated: 2025/06/16 21:24:42 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static int	ft_wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free_all(char **tab, int i)
{
	while (i--)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static char	**fill_tab(char **tab, const char *s, char c, int words)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] == c)
			i++;
		len = ft_wordlen(s + i, c);
		tab[j] = malloc(sizeof(char) * (len + 1));
		if (!tab[j])
			return (ft_free_all(tab, j), NULL);
		ft_strlcpy(tab[j++], s + i, len + 1);
		i += len;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_word(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	return (fill_tab(tab, s, c, words));
}

/*static int	ft_count_word(const char *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static int	ft_strlen_c(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_strdup_split(const char *s, char c)
{
	int		i;
	char	*copy;
	int		len;

	len = ft_strlen_c(s, c);
	copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	ft_free_split(char **split, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (split == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			split[j] = ft_strdup_split(&s[i], c);
			if (split[j] == NULL)
			{
				ft_free_split(split, j);
				return (NULL);
			}
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	split[j] = NULL;
	return (split);
}*/
/*static int	ft_count_word(char *s, char c)
{
	i = 0;
	count = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (i > 0 && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static int	ft_strlen_c(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_strdup_split(char **split, char *s, char c)
{
	int		i;
	char	*copy;

	i = 0;
	copy = malloc((ft_strlen_c(s, c) * (sizeof(char)) + 1));
	if (copy == NULL)
	{
		free(split);
		return (NULL);
	}
	while (s[i] && s[i] != c)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static char	**ft_supr(char **split, int j)
{
	while (--j)
		free(split[j]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*cpy;
	int		i;
	int		j;
	char	**split;
	char	*cpy;
	int		i;
	int		j;
	int		i;
	char	**bis;

	cpy = ft_strtrim(s, &c);
	split = malloc(sizeof(char *) * (ft_count_word(cpy, c) + 1));
	j = 0;
	i = 0;
	if (split == NULL)
		return (NULL);
	while (cpy[i])
	{
		if (cpy[i] != c)
		{
			split[j++] = ft_strdup_split(split, &cpy[i], c);
			i += ft_strlen_c(&cpy[i], c);
			if (split[j - 1] == NULL)
				return (ft_supr(split, j));
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}*/
/*char	**ft_split(char const *s, char c)
{
	cpy = ft_strtrim(s, &c);
	if (cpy == NULL)
		return (NULL);
	if (cpy[0] == '\0')
	{
		split = malloc(sizeof(char *) * 1);
		if (!split)
			return (NULL);
		split[0] = NULL;
		free(cpy);
		return (split);
	}
	split = malloc(sizeof(char *) * (ft_count_word(cpy, c) + 1));
	j = 0;
	i = 0;
	if (split == NULL)
		return (NULL);
	while (cpy[i])
	{
		if (cpy[i] != c)
		{
			split[j++] = ft_strdup_split(split, &cpy[i], c);
			i += ft_strlen_c(&cpy[i], c);
			if (split[j - 1] == NULL)
				return (ft_supr(split, j));
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}*/
/*#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		i = 0;
		bis = ft_split(argv[1], ',');
		if (!bis)
			return (printf("ERREUR/n"));
		while (bis[i])
		{
			printf("%s\n", bis[i]);
			i ++;
		}
		free(bis);
		}
}*/
/*split[j] = malloc(ft_strlen(&cpy[i], c) * (sizeof(char) + 1));
if (split[j] == NULL)
{
	free(split);
	return (NULL);
}
while (cpy[i] && cpy[i] != c)
{
	split[j][u] = cpy[i];
	i ++;
	u ++;
}
split[j][u] = '\0';
u = 0;
while (s[i] == c)
	i ++;
j++;*/

/*char	**ft_remplir(char **split, char *cpy, char c, int i, int j)
{
	int	u;

	u = 0;
	split[j] = malloc(ft_strlen(&cpy[i], c) * (sizeof(char) + 1));
	if (split[j] == NULL)
	{
		free(split);
		return (NULL);
	}
	while (cpy[i] && cpy[i] != c)
	{
		split[j][u] = cpy[i];
		i ++;
		u ++;
	}
	split[j][u] = '\0';
	u = 0;
	return (split);
}*/