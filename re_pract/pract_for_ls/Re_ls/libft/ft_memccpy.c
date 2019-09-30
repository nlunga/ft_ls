/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:20:41 by nlunga            #+#    #+#             */
/*   Updated: 2019/06/13 09:55:40 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*dest;
	const char				*srcs;
	unsigned char			k;
	size_t					i;

	i = 0;
	k = (unsigned char)c;
	dest = (unsigned char *)dst;
	srcs = (char *)src;
	while (n > 0)
	{
		dest[i] = srcs[i];
		if (dest[i] == k)
			return (dst + 1 + i);
		i++;
		n--;
	}
	return (NULL);
}
