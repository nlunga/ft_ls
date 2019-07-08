/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:18:19 by nlunga            #+#    #+#             */
/*   Updated: 2019/06/05 15:29:35 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *to, const char *from, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (to[i])
		i++;
	while (from[j] && n > 0)
	{
		to[i] = from[j];
		i++;
		j++;
		n--;
	}
	to[i] = '\0';
	return (to);
}
