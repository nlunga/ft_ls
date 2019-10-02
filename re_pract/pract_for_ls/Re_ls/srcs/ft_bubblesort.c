/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:43:17 by nlunga            #+#    #+#             */
/*   Updated: 2019/10/02 18:19:29 by innocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

void	ft_bubblesort(t_dir order[])
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

int		sort_time(char *file, char *file2)
{
	struct stat		buff;
	struct stat		buff2;

	stat(file, &buff);
	stat(file2, &buff2);
	return (buff.st_mtime < buff2.st_mtime);
}

void	ft_swap_str(char **str, char **str1)
{
	char	*temp;

	temp = *str;
	*str = *str1;
	*str1 = temp;
}

void	ft_store_time(char **path, char **path1, char *str)
{
	struct stat		buf;
	struct stat		buf1;
	//struct timespec st_mtim;
	char			*s1;
	char			*s2;

	s1 = ft_strjoin(str, *path);
	s2 = ft_strjoin(str, *path1);
	stat(s1, &buf);
	stat(s2, &buf1);
	if (buf.st_mtime < buf1.st_mtime)
		ft_swap_str(path, path1);
	else
	{
		if (buf.st_mtime == buf1.st_mtime)
		{
//			if (buf.st_mtimespec.tv_nsec < buf1.st_mtimespec.tv_nsec)
			if (buf.st_mtim.tv_sec < buf1.st_mtim.tv_sec)
				ft_swap_str(path, path1);
		}
	}
}

char	**ft_tflag(char *dir, char **array, int n)
{
	int		i;
	int		k;
	char	*str;

	str = ft_strjoin(dir, "/");
	i = 0;
	while (i < n - 1)
	{
		k = 0;
		while (k < (n - i - 1))
		{
			ft_store_time(&array[k], &array[k + 1], str);
			k++;
		}
		i++;
	}
	free(str);
	return (array);
}
