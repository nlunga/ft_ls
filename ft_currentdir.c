/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_currentdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:41:41 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/13 21:45:12 by nlunga           ###   ########.fr       */
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

void	ft_opendirtime(char *path, t_dir data[])
{
	DIR				*dir;
	struct dirent	*sd;
	struct stat		buf;
	int				i;

	i = 0;
	dir = opendir(path);
	if (dir == NULL)
		ft_putendl("noooo Error!!!");
	while ((sd = readdir(dir)) != NULL)
	{
		data[i].name = ft_strdup(sd->d_name);
		if (lstat(data[i].name, &buf) < 0)
		{
			perror(data[i].name);
			return ;
		}
		data[i].mtime = buf.st_mtime;
		i++;
	}
	closedir(dir);
}

void	ft_opendir(char *path, t_dir data[])
{
	DIR				*dir;
	struct dirent	*sd;
	int				i;

	i = 0;
	if ((dir = opendir(path)) == NULL)
	{
		perror(path);
		return ;
	}
	while ((sd = readdir(dir)) != NULL)
	{
		data[i].name = ft_strdup(sd->d_name);
		i++;
	}
	closedir(dir);
}

void	ft_displayrev(t_dir test[], int n)
{
	n--;
	ft_stuct_sort(test);
	while (n >= 0)
	{
		if (*test[n].name != '.')
		{
			ft_putendl(test[n].name);
			ft_strdel(&test[n].name);
		}
		n--;
	}
}

void	ft_stuct_sort(t_dir order[])
{
	int		i;
	int		sort;
	char	*temp;

	sort = 0;
	while (!sort)
	{
		i = 0;
		while (order[i + 1].name)
		{
			if (ft_strcmp(order[i].name, order[i + 1].name) > 0)
			{
				temp = order[i].name;
				order[i].name = order[i + 1].name;
				order[i + 1].name = temp;
			}
			i++;
		}
		i = 0;
		sort = 1;
		while (order[i + 1].name && sort)
		{
			if (ft_strcmp(order[i].name, order[i + 1].name) > 0)
				sort = 0;
			i++;
		}
	}
}
