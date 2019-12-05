/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 08:28:20 by nlunga            #+#    #+#             */
/*   Updated: 2019/06/05 14:48:43 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *to, const char *from, size_t dstsize)
{
	size_t		len;
	size_t		i;

	len = ft_strlen(to);
	i = 0;
	while (i + len < dstsize - 1 && from[i] && dstsize > 0)
	{
		to[len + i] = from[i];
		i++;
	}
	to[len + i] = '\0';
	if (dstsize < i + len)
		return (dstsize + ft_strlen(from));
	return (len + ft_strlen(from));
}
