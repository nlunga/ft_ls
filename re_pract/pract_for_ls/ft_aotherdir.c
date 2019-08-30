/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aotherdir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:44:42 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/30 23:40:40 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_aotherdir(char *argv, d_list *find_data)
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
		find_data->strings[i] = ft_strdup(sd->d_name);
		i++;
	}
	closedir(dir);
}
