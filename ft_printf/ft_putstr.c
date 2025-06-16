/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:19:04 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/21 17:42:14 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int n)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		write(1, &s[i++], 1);
	if (n == 1)
		free(s);
	return (i);
}

/*int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		ft_putstr_fd(argv[1], ft_atoi(argv[2]));
	}
}*/