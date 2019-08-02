/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_currentdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:41:41 by nlunga            #+#    #+#             */
/*   Updated: 2019/07/22 08:36:31 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_currentdir(int argc, char **argv)
{
	DIR				*dir;
	struct dirent	*sd;

	if (argc == 1)
	{
		if (argv[0])
		{
			dir = opendir(".");
			if (dir == NULL)
			{
				ft_putendl("ERROR! unable to open directory");
			}
			while ((sd = readdir(dir)) != NULL)
			{
				if (*sd->d_name != '.')
					ft_putendl(sd->d_name);
			}

			closedir(dir);
		}
	}
}
