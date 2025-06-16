/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:32:36 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/21 17:44:31 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len2(unsigned long n)
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

static	char	*ft_swap2(int len, char *s1)
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

char	*ft_hexa_add(unsigned long n, char *set)
{
	int				i;
	char			*s1;
	int				len;

	i = 0;
	len = hex_len2(n);
	s1 = malloc(len + 1);
	if (!s1)
		return (NULL);
	while (n > 0)
	{
		s1[i] = set[(n % 16)];
		n /= 16;
		i++;
	}
	s1[i] = '\0';
	return (ft_swap2(len, s1));
}

int	ft_putadd(void *ptr)
{
	int	total;

	total = 0;
	if (ptr == NULL)
	{
		total += ft_putstr("(nil)", 0);
		return (5);
	}
	total += ft_putstr("0x", 0);
	total += ft_putstr(ft_hexa_add((unsigned long)ptr, "0123456789abcdef"), 1);
	return (total);
}
