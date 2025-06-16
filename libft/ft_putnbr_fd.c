/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:48:22 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/05 13:42:49 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	div;

	div = 1;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	while (n / div > 9)
		div *= 10;
	while (div > 0)
	{
		ft_putchar_fd(((n / div) + '0'), fd);
		n %= div;
		div /= 10;
	}
}
/*int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		ft_putnbr_fd(ft_atoi(argv[1]), ft_atoi(argv[2]));
	}
}*/