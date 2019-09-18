/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:07:59 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/18 16:14:56 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_str(char *str, char *str1)
{
	char	*temp;

	temp = *str;
	*str = *str1;
	*str1 = temp;
}

void	ft_store_time(char **path, char **path1, char str)
{
	struct stat		buf;
	struct stat		buf1;
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
			if (buf.st_mtimespec.tv_nsec < buf1.st_mtimespec.tv_nsec)
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
