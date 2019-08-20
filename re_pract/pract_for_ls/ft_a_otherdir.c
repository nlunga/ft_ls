/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_otherdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:44:42 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/20 11:05:44 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/errno.h>

void	ft_a_otherdir(char *argv, d_list *find_data)
{
	
	DIR				*dir;
	struct dirent 	*sd;
	size_t			i;
	
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
	i = 0;
	while((sd = readdir(dir)) != NULL)
	{
		find_data->dir_strings[i] = ft_strdup(sd->d_name);
		i++;
	//	ft_putendl(sd->d_name);
	}

	closedir(dir);
}
