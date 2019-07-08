/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrpl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:13:32 by nlunga            #+#    #+#             */
/*   Updated: 2019/06/27 17:02:23 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrpl(char *str,int c, int d)
{
	char	*temp;
	int		i;
	
	if (!(temp = ft_strnew(ft_strlen(str))))
		return (NULL);
	temp = str;
	i = 0;
	while (temp[i])
	{
		if (temp[i] == (unsigned char)c)
			temp[i] = (unsigned char)d;
		i++;
	}
	return (temp);
}

int	main(void)
{
	char str[50] = "My name is Innocent # I";
	
	ft_putnbr('\n');
	ft_putendl(ft_strrpl(str, '#', '&'))
	return (0);
}
