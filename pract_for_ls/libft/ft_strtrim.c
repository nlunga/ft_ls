/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:31:33 by nlunga            #+#    #+#             */
/*   Updated: 2019/06/20 13:50:22 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == 32 || s[i] == '\v' || s[i] == '\b')
		i++;
	if (s[i] == '\0')
		return (ft_strdup(s + i));
	while ((s[j] == '\n' || s[j] == '\t' || s[j] == 32 || s[i] == '\v' || s[i] == '\b') && j > 0)
		j--;
	return (ft_strsub(s, i, j - i + 1));
}
