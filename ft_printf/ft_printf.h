/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:44:04 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/21 17:42:37 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_conv_hexa(unsigned int n, char c);

int		ft_printf(const char *format, ...);
int		ft_putadd(void *ptr);
int		ft_putchar(char c);
int		ft_putnbr_unsigned(unsigned int num);
int		ft_putnbr(int n);
int		ft_putstr(char *s, int n);
int		ft_strlen(const char *s);

#endif