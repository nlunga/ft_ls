/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otherdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:44:42 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/13 22:47:31 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_otherdir(char *argv, d_list *find_data)
{
	DIR				*dir;
	struct dirent	*sd;
	int				i;

	dir = opendir(argv);
	if (dir == NULL)
	{
		perror(argv);
		exit(1);
	}
	i = 0;
	while ((sd = readdir(dir)) != NULL)
	{
		if (*sd->d_name != '.')
		{
			find_data->dr[i] = ft_strdup(sd->d_name);
			i++;
		}
	}
	ft_bubblesort(find_data->dr);
	closedir(dir);
}
