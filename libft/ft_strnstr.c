/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:46:59 by nlunga            #+#    #+#             */
/*   Updated: 2019/06/07 14:12:33 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	size_t			i;
	size_t			j;

	i = 0;
	if (*needle == '\0')
		return ((char *)hay);
	while (hay[i] != '\0' && i < n)
	{
		j = 0;
		while (needle[j] == hay[i + j] && (j + i) < n)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&hay[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
