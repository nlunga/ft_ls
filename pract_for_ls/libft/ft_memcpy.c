/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:57:12 by nlunga            #+#    #+#             */
/*   Updated: 2019/06/13 16:38:00 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dest;
	char			*srcs;
	size_t			i;

	dest = (char *)dst;
	srcs = (char *)src;
	i = 0;
	if (dest == NULL && srcs == NULL)
		return (NULL);
	while (i < n)
	{
		dest[i] = srcs[i];
		i++;
	}
	return (dest);
}
