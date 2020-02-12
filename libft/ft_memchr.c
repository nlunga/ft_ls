/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:16:59 by nlunga            #+#    #+#             */
/*   Updated: 2019/06/15 09:06:30 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					index;
	unsigned const char		*str;

	index = 0;
	str = (unsigned const char *)s;
	while (n)
	{
		if (str[index] == (unsigned char)c)
			return ((char *)&str[index]);
		index++;
		n--;
	}
	return (NULL);
}
