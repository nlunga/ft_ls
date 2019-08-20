/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_currentdir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:41:41 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/20 10:12:16 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_a_currentdir(d_list *find_data)
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
		find_data->strings[i] = ft_strdup(sd->d_name);
		i++;
		//ft_putendl(sd->d_name);
	}
	closedir(dir);
}
