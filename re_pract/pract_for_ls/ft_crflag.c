/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:31:34 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/31 11:22:39 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
void	ft_reopen(char **path, d_list *find_data)
{
	int d;
	int a;

	d = 0;
	a = 0;

	ft_otherdir(path[d], find_data);
	while (path[d] != NULL)
	{
		if (ft_isdir(path[d]))
		{
			
			a++;
		}
		d++;
	}
}
*/

void	ft_read_store(int argc, char *path, d_list *find_data)
{
	int	i;
	int c;

	i = 0;
	c = 0;
	if (argc == 2)
	{
		path = ft_strdup(".");
		ft_otherdir(path, find_data);
	}
	else
		ft_otherdir(path, find_data);
	while (find_data->dir_strings[i] != NULL)
	{
		if (ft_isdir(find_data->dir_strings[i]))
		{
			find_data->big_r[c] = ft_strdup(find_data->dir_strings[i]);
			c++;
		}
		ft_putendl(find_data->dir_strings[i]);
		ft_strdel(&find_data->dir_strings[i]);
		i++;
	}

	ft_putendl(" ");
}

void	ft_crflag(int argc, char **argv, t_flags *m_flags, d_list *find_data)
{
	ft_verflag(argc, argv, m_flags);
	if (m_flags->cr_flag == 1)
	{
		if (argc == 2)
		{
			int i;
			int c;
			int d;

			i = 0;
			d = 0;
			c = 0;
			ft_read_store(argc,".", find_data);
			ft_crflag(argc, find_data->big_r, m_flags, find_data);
			ft_putendl(find_data->big_r[0]);
			ft_putendl(find_data->big_r[1]);
			ft_putendl(find_data->big_r[2]);
			ft_putendl(find_data->big_r[3]);
			ft_putendl(find_data->big_r[4]);
	/*		
			find_data->path = ft_strdup(ft_strcat(find_data->big_r[0], "/"));
			while (find_data->big_r[d] != NULL)
			{
				ft_otherdir(find_data->big_r[d], find_data);
				ft_crflag(argc, find_data->path, m_flags, find_data);
				ft_strdel(find_data->path);
				d++;
			}*/
		}
	}
}
