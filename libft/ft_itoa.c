/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:46:24 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/06 18:42:49 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sized(int n)
{
	int	d;

	d = 1;
	while (n / d > 9)
		d *= 10;
	return (d);
}

static int	ft_sizec(int n)
{
	int	d;
	int	c;

	d = 1;
	c = 1;
	while (n / d > 9)
	{
		d *= 10;
		c++;
	}
	return (c);
}

static char	*ft_string(char *s, int n2, int d)
{
	int	i;

	i = 0;
	if (n2 < 0)
	{
		s[i++] = '-';
		n2 *= -1;
	}
	while (d > 0)
	{
		s[i++] = (n2 / d) + '0';
		n2 %= d;
		d /= 10;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_intmin(char *set)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc(12 * sizeof(char));
	if (!s)
		return (NULL);
	while (set[i])
	{
		s[i] = set[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		d;
	int		c;
	int		n2;

	if (n == -2147483648)
		return (ft_intmin("-2147483648"));
	n2 = n;
	if (n < 0)
		n = -n;
	d = ft_sized(n);
	c = ft_sizec(n);
	if (n2 < 0)
		s = malloc(sizeof(char) * (c + 2));
	else
		s = malloc(sizeof(char) * (c + 1));
	if (!s)
		return (NULL);
	return (ft_string(s, n2, d));
}

/*#include "libft.h"

static int	ft_sized(int n)
{
	int	d;

	d = 1;
	while (n / d > 9)
	{
		d *= 10;
	}
	return (d);
}

static int	ft_sizec(int n)
{
	int	d;
	int	c;

	d = 1;
	c = 1;
	while (n / d > 9)
	{
		d *= 10;
		c ++;
	}
	return (c);
}

static char	*ft_string(char *s, int n2, int d, int c)
{
	int	i;

	i = 0;
	if (n2 < 0)
	{
		s[i] = '-';
		n2 *= -1;
		i++;
		c++;
	}
	while (i <= c)
	{
		s[i++] = (n2 / d) + '0';
		n2 %= d;
		d /= 10;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_intmin(char *set)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc(12 * sizeof(char));
	if (s == NULL)
		return (s);
	while (set[i])
	{
		s[i] = set[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		d;
	int		c;
	int		n2;

	n2 = n;
	if (n == -2147483648)
		return (ft_intmin("-2147483648"));
	if (n2 < 0)
		n *= -1;
	d = ft_sized(n);
	c = ft_sizec(n);
	if (n2 < 0)
		s = malloc(c * sizeof(char) + 2);
	else
		s = malloc(c * sizeof(char) + 1);
	if (s == NULL)
		return (s);
	return (ft_string(s, n2, d, c));
}*/

/*#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("Ma fonction : %s\n", ft_itoa(ft_atoi(argv[1])));
		printf("Ma fonction : %s\n", ft_itoa(ft_atoi(argv[1])));

	}
}*/
