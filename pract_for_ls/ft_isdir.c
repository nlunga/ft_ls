/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:17:59 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/12 11:39:53 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isdir(int argc, char **argv)
{
	struct stat		buf;
	int				i;

	if (ft_check_flags(argc, argv) == 0)
	{
		i = 1;
		while (argv[i])
		{
			stat(argv[i], &buf);
			if(S_ISDIR(buf.st_mode))
   				return (1);
			else
   				return (0);		
   			i++;
		}
	}
	return (0);
}
