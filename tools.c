/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:35:18 by nlunga            #+#    #+#             */
/*   Updated: 2019/10/03 16:16:50 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isdir(char *path)
{
	struct stat	buf;

	stat(path, &buf);
	if (S_ISDIR(buf.st_mode))
		return (1);
	else
		return (0);
}

int		ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

int		ft_structlen(t_dir gets[])
{
	int	i;

	i = 0;
	while (gets[i].name != NULL)
		i++;
	return (i);
}

void	ft_displaytime(t_dir test[], int n)
{
	n--;
	number_sort(test, n);
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

void	number_sort(t_dir order[], int n)
{
	int		i;
	int		j;
	t_dir	temp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (order[j].mtime > order[j + 1].mtime)
			{
				temp = order[j];
				order[j] = order[j + 1];
				order[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
