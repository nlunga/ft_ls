/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_currentdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:41:41 by nlunga            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/23 15:11:22 by nlunga           ###   ########.fr       */
=======
/*   Updated: 2019/09/13 21:45:12 by nlunga           ###   ########.fr       */
>>>>>>> b761845e4f8a3cb5a090ecaa31907f0ba8909537
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_currentdir(d_list *find_data)
{
	DIR				*dir;
	struct dirent	*sd;
	size_t			i;

	dir = opendir(".");
	if (dir == NULL)
	{
		ft_putendl("ERROR! unable to open directory");
	}
	i = 0;
	while ((sd = readdir(dir)) != NULL)
	{
		if (*sd->d_name != '.')
		{
			find_data->strings[i] = ft_strdup(sd->d_name);
			i++;
		}
	}
	closedir(dir);
}
