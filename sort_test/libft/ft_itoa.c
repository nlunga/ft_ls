/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:22:48 by nlunga            #+#    #+#             */
/*   Updated: 2019/06/18 11:15:20 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*fresh;
	int		temp;

	i = ft_intlen(n);
	temp = n;
	if (!(fresh = ft_strnew(i)))
		return (NULL);
	fresh[i] = '\0';
	i--;
	if (temp == -2147483648)
		return (fresh = ft_strdup("-2147483648"));
	if (temp < 0)
		temp = temp * -1;
	while (temp >= 10)
	{
		fresh[i] = (temp % 10) + '0';
		temp = temp / 10;
		i--;
	}
	fresh[i] = (temp % 10) + '0';
	i--;
	if (n < 0)
		fresh[i] = '-';
	return (fresh);
}
