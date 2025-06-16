/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:40:29 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/05 13:55:31 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*address;
	size_t			i;

	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	address = malloc(nmemb * size);
	if (address == NULL)
		return (address);
	i = 0;
	while (i < (nmemb * size))
	{
		address[i] = 0;
		i++;
	}
	return (address);
}
