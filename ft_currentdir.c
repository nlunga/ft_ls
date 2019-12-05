/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_currentdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:41:41 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/16 17:29:00 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_currentdir(int argc, char **argv, d_list *get_data)
{
	DIR				*dir;
	struct dirent	*sd;
	size_t			i;

	if (argc == 1)
	{
		if (argv[0])
		{
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
					get_data->strings[i] = ft_strdup(sd->d_name);
					//printf("%s\n", get_data->strings[i]);
					i++;
					//printf("%s\n", ft_strcat("./", sd->d_name));
				}
			}
			closedir(dir);
		}
	}
//	free(get_data);
}
