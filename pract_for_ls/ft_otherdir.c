/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otherdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:44:42 by nlunga            #+#    #+#             */
/*   Updated: 2019/07/19 16:22:02 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_otherdir(char *argv)
{
	
	DIR				*dir;
	struct dirent 	*sd;
	
	dir = opendir(argv);
	if (dir == NULL)
	{
		ft_putendl("WQWQEQEQEQEQ  ERROR! unable to open directory");
		exit(1);
	}
	while((sd = readdir(dir)) != NULL)
	{
	//	ft_putstr("->> ");
//		if (*sd->d_name != '.')
			ft_putendl(sd->d_name);
	}

	closedir(dir);
}
