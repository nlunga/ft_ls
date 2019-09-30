/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:15:43 by nlunga            #+#    #+#             */
/*   Updated: 2019/06/14 14:06:20 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*dest;
	const unsigned char		*srcs;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	srcs = (const unsigned char *)src;
	if (dest > srcs)
		while (len--)
			dest[len] = srcs[len];
	else if (dest < srcs)
		ft_memcpy(dest, srcs, len);
	return (dest);
}
