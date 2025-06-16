/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:06:21 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/21 17:46:23 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_checkfill(char c, va_list *args, int *total)
{
	if (c == 'd' || c == 'i')
		*total += ft_putnbr(va_arg(*args, int));
	else if (c == '%')
		*total += ft_putchar('%');
	else if (c == 's')
		*total += ft_putstr(va_arg(*args, char *), 0);
	else if (c == 'c')
		*total += ft_putchar((char)va_arg(*args, int));
	else if (c == 'u')
		*total += ft_putnbr_unsigned(va_arg(*args, unsigned int));
	else if (c == 'x' || c == 'X')
		*total += ft_putstr(ft_conv_hexa(va_arg(*args, unsigned int), c), 1);
	else if (c == 'p')
		*total += ft_putadd(va_arg(*args, void *));
	else
		return ;
}

int	ft_printf(const char *format, ...)
{
	int				i;
	int				total;
	va_list			args;

	i = 0;
	total = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				ft_checkfill(format[i], &args, &total);
		}
		else if (format[i] != '%')
			total += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (total);
}

/*#include <stdio.h> 
int main(void)
{
	int p = 0;
	int *ptr = &p;
	ft_printf("MA FONCTION : %d\n\n", ft_printf("Je suis %s, mon initiale est : %c, 
j'ai %d ans ou %u, en hexa : %x et en maj %X, le print %%, et je ptr : %p\n", 
"Matthieu LEMEE", 'M', -23, 23, 248913, 248913, ptr));
	ft_printf("\n\n");
	printf("VRAIE FONCTION : %d\n\n", printf("Je suis %s, mon initiale est : %c, 
		j'ai %d ans ou %u, en hexa : %x et en maj %X, le print %%, et je ptr : %p\n", 
		"Matthieu LEMEE", 'M', -23, 23, 248913, 248913, ptr));
}*/