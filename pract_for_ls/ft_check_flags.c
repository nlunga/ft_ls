/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:00:28 by nlunga            #+#    #+#             */
/*   Updated: 2019/07/19 18:48:04 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_check_flags(int argc, char **argv)
{
	int i;
	char	*option;

	i = 0;
	if (argc < 2)
		exit(1);
	else
	{
		while (argv[i])
		{
			if (argv[i][0] == '-')
			{
				if (!(option = ft_strnew(ft_strlen(argv[i]))))
					return (NULL);
				option = argv[i];
			}
			i++;
		}
	}
}

// The last option specified in each pair determines the output format
// By default, the ls command displays all information in alphabetic order by file name
// When the ls command displays the contents of a directory, it does not show entries for files whose names begin with a . (dot) unless you use the -a or -A flag
