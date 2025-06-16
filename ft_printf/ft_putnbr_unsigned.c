/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:24:59 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/16 18:26:48 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int num)
{
	unsigned int	div;
	int				count;

	div = 1;
	count = 0;
	while (num / div > 9)
		div *= 10;
	while (div >= 1)
	{
		count += ft_putchar((num / div) + '0');
		num %= div;
		div /= 10;
	}
	return (count);
}
/*#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_putnbr_unsigned(atoi(argv[1]));
	}
}*/