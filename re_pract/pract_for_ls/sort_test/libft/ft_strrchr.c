/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:25:46 by nlunga            #+#    #+#             */
/*   Updated: 2019/06/07 10:18:20 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *s;

	s = NULL;
	while (*str)
	{
		if (*str == (char)c)
			s = (char *)str;
		str++;
	}
	if (*str == (char)c)
		s = (char *)str;
	return (s);
}
