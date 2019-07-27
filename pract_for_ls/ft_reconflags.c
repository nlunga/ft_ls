/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reconflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:02:24 by nlunga            #+#    #+#             */
/*   Updated: 2019/07/27 11:21:16 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_reconflags(int argc, char **argv)
{
	if (ft_check_flags(argc, argv) == 1)
	{
		int i;
		int j;
//		struct s_flags m_flags;

		i = 1;
		while (argv[i])
		{
			j = 1;
			while (argv[i][j] != '\0')
			{
				if (ft_check_multi(argv[i], argv[i][j], j) == 1)
				{
					if (argv[i][j] == 'l')
						ft_flags(argc, argv);//ft_lflag(argc, argv);//printf("this is an 'l' flag\n");
					else if (argv[i][j] == 'a')
						printf("this is an 'a' flag\n");
					else if (argv[i][j] == 'r')
						printf("this is an 'r' flag\n");
					else if (argv[i][j] == 't')
						printf("this is an 't' flag\n");
					else if (argv[i][j] == 'R')
						printf("this is an 'R' flag\n");
				}
				j++;
			}
			i++;
		}
	}
	return (0);
}
