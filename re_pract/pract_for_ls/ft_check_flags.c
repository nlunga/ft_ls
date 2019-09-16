/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:00:28 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/23 14:42:38 by nlunga           ###   ########.fr       */
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
				break;
			if (argv[i][0] == '-')
			{
				return (1);
			}
			i++;
		}
	}
	return (0);
}

// The last option specified in each pair determines the output format
// By default, the ls command displays all information in alphabetic order by file name
// When the ls command displays the contents of a directory, it does not show entries for files whose names begin with a . (dot) unless you use the -a or -A flag
