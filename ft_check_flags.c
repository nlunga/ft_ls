/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:00:28 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/02 08:58:01 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_check_flags(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
		exit(1);
	else
	{
		while (argv[i])
		{
			if (argv[i][0] != '-')
				break ;
			if (argv[i][0] == '-')
			{
				return (1);
			}
			i++;
		}
	}
	return (0);
}
