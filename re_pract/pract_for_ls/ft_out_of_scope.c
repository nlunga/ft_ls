/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out_of_scope.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 08:38:09 by nlunga            #+#    #+#             */
/*   Updated: 2019/07/29 09:41:24 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_out_of_scope(int argc, char **argv)
{
	int i;
	int j;

	if (argc < 2)
	{
		i = 1;
		while (argv[i])
		{
			j = 1;
			while (argv[i][j] != '\0')
			{
				if (argv[i][j] != 'l' && argv[i][j] != 'a' && argv[i][j] != 'r' && argv[i][j] != 't' && argv[i][j] != 'R')
				{
					printf("ft_ls: illegal option -- %c", argv[i][j]);
				}
				j++;
			}
			i++;
		}
	}
	return (0);
}
