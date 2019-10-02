/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 09:29:08 by nlunga            #+#    #+#             */
/*   Updated: 2019/10/02 14:52:21 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

/*
void	ft_opendir(char *path, t_dir *data)
{
	DIR				*dir;
	struct dirent	*sd;
	int				i;

	i = 0;
	dir = opendir(path);
	if (dir == NULL)
		ft_putendl("Error!!!");
	while ((sd = readdir(dir)) != NULL)
	{
		if (*sd->d_name != '.')
		{
			data[i]->name = ft_strdup(sd->d_name);
			i++;
		}
	}
//	ft_bubblesort(&data->name);
	closedir(dir);
}
*/

void	ft_opendir(char *path, t_dir data[])
{
	DIR				*dir;
	struct dirent	*sd;
	int				i;

	i = 0;
	dir = opendir(path);
	if (dir == NULL)
		ft_putendl("Error!!!");
	while ((sd = readdir(dir)) != NULL)
	{
			data[i].name = ft_strdup(sd->d_name);
			i++;
	}
//	ft_bubblesort(&data->name);
	//ft_bubblesort(data);
	closedir(dir);
}
