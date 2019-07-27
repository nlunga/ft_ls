/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:17:59 by nlunga            #+#    #+#             */
/*   Updated: 2019/07/22 12:02:04 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/errno.h> // must delete this header file
int		ft_isdir(int argc, char **argv)
{
	struct stat		buf;
	int				i;

	if (argc < 2)
		exit(1);
	else
	{
		if (&ft_check_flags == 0)
		{
			i = 1;
			while (argv[i])
			{
			/*	if(stat(argv[i], buf) == -1)
				{
      				perror("stat");
      				return errno;
				}*/
				stat(argv[i], &buf);
				if(S_ISDIR(buf.st_mode))
   					printf(" Its a directoy\n");
				else
   					printf("Its a file\n");		
   				i++;
			}
		}
	}
	return (0);
}
/*
if(stat(currentPath, &buf) == -1)
{
      perror("stat");
      return errno;
}*/

