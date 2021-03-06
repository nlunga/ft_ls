/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_currentdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:41:41 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/06 10:15:26 by nlunga           ###   ########.fr       */
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
