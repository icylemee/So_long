/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:08:44 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/06 18:07:47 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*save;
	const unsigned char	*source;

	save = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if ((!dest && !src) || n == 0)
		return (dest);
	while (n--)
		*save++ = *source ++;
	return (dest);
}
