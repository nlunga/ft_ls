/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:22:02 by nlunga            #+#    #+#             */
/*   Updated: 2019/06/13 15:14:35 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*p;

	if (!(p = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(p, size + 1);
	return (p);
}
