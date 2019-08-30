/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otherdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:44:42 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/30 22:30:48 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_otherdir(char *argv, d_list *find_data)
{
	DIR				*dir;
	struct dirent 	*sd;
	int				i;
	
	dir = opendir(argv);
	if (dir == NULL)
	{
		perror("opendir");
		exit(1);
	}
	i = 0;
	while((sd = readdir(dir)) != NULL)
	{
		if (*sd->d_name != '.')
		{
			find_data->dir_strings[i] = ft_strdup(sd->d_name);
			ft_putendl(find_data->dir_strings[i]);
			i++;
		}
	}
	closedir(dir);
}
