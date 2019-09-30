/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noWhite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:28:17 by nlunga            #+#    #+#             */
/*   Updated: 2019/06/20 13:45:01 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_noWhite(char const *s)
{
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] <= 0 || s[i] >= 32)
		i++;
	if (s[i] == '\0')
		return (ft_strdup(s + i));
	while ((s[j] <= 0 || s[j] >= 32) && j > 0)
		j--;
	return (ft_strsub(s, i, j - i + 1));
}
