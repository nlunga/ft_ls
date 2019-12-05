/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otherdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:44:42 by nlunga            #+#    #+#             */
/*   Updated: 2019/07/23 11:05:49 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/errno.h>

void	ft_otherdir(char *argv)
{
	
	DIR				*dir;
	struct dirent 	*sd;
	
	dir = opendir(argv);
	if (dir == NULL)
	{
		//ft_putendl(strerror(errno));
		perror("opendir");
		exit(1);
	}
	/*
			if (errno == 20)
				ft_putendl(*argv);
			else
				perror("opendir");
			exit(1);
	*/
	while((sd = readdir(dir)) != NULL)
	{
		if (*sd->d_name != '.')
			ft_putendl(sd->d_name);
	}

	closedir(dir);
}
