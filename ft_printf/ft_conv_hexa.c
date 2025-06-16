/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:17:47 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/21 17:39:37 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned long n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static	char	*ft_swap(int len, char *s1)
{
	int				len2;
	char			temp;
	int				i;

	i = 0;
	len--;
	len2 = len;
	while (i <= (len / 2))
	{
		temp = s1[i];
		s1[i] = s1[len2];
		s1[len2] = temp;
		i++;
		len2--;
	}
	return (s1);
}

static char	*ft_fillset(char *hex)
{
	char	*set;
	int		i;

	i = 0;
	set = malloc(17);
	if (!set)
		return (NULL);
	while (hex[i])
	{
		set[i] = hex[i];
		i++;
	}
	set[i] = '\0';
	return (set);
}

char	*ft_conv_hexa(unsigned int n, char c)
{
	int				i;
	char			*s1;
	int				len;
	char			*set;

	i = 0;
	len = hex_len(n);
	s1 = malloc(len + 1);
	if (!s1)
		return (NULL);
	if (n == 0)
		s1[i++] = '0';
	if (c == 'x')
		set = ft_fillset("0123456789abcdef");
	if (c == 'X')
		set = ft_fillset("0123456789ABCDEF");
	while (n > 0)
	{
		s1[i] = set[(n % 16)];
		n /= 16;
		i++;
	}
	s1[i] = '\0';
	free(set);
	return (ft_swap(len, s1));
}

/*char	*ft_conv_hexa(unsigned int n, const char *set)
{
	int				i;
	char			*s1;
	int				len;

	len = hex_len(n);
	s1 = malloc(len + 1);
	i = 0;
	while (n > 0)
	{
		s1[i] = set[(n % 16)];
		n /= 16;
		i++;
	}
	s1[i] = '\0';
	return (ft_swap(len, s1));
}*/
/*char	*ft_conv_hexa(unsigned int n, const char *set)
{
	int				i;
	char			*s1;
	int				len;

	len = hex_len(n);
	s1 = malloc(len + 1);
	i = 0;
	while (n > 0)
	{
		s1[i] = set[(n % 16)];
		n /= 16;
		i++;
	}
	s1[i] = '\0';
	return (ft_swap(len, s1));
}*/

/*char	*ft_conv_hexa(unsigned int n, const char *set)
{
	int				i;
	char			*s1;
	int				len2;
	char			temp;
	int				len;

	len = hex_len(n);
	s1 = malloc(len + 1);
	i = 0;
	while (n > 0)
	{
		s1[i] = set[(n % 16)];
		n /= 16;
		i++;
	}
	s1[i] = '\0';
	i = 0;
	len--;
	len2 = len;
	while (i <= (len / 2))
	{
		temp = s1[i];
		s1[i] = s1[len2];
		s1[len2] = temp;
		i++;
		len2--;
	}
	return (s1);
}*/

/*int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%s\n", ft_conv_hexa(atoi(argv[1]), "0123456789abcdef"));
	}
}*/
