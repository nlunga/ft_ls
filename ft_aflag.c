/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:20:55 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/13 21:31:02 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_multi_a(char **argv, int i, d_list *find_data)
{
	int	d;

	while (argv[i] != NULL)
	{
		d = 0;
		find_data->path = ft_strdup(ft_strjoin(argv[i], "/"));
		ft_putstr(argv[i]);
		ft_putendl(":");
		ft_putendl(find_data->strings[d]);
		ft_aotherdir(find_data->path, find_data);
		while (find_data->strings[d] != NULL)
		{
			ft_putendl(find_data->strings[d]);
			ft_strdel(&find_data->strings[d]);
			d++;
		}
		ft_putendl(" ");
		i++;
	}
}

void	ft_only_a(d_list *find_data, int i)
{
	ft_aotherdir(".", find_data);
	while (find_data->strings[i] != NULL)
	{
		ft_putendl(find_data->strings[i]);
		ft_strdel(&find_data->strings[i]);
		i++;
	}
}

void	ft_aflag(int argc, char **argv, t_flags *m_flags, d_list *find_data)
{
	int	i;

	i = 1;
	while (i < argc && ft_check_flags(argc, argv) == 0)
		i++;
	i++;
	ft_verflag(argc, argv, m_flags);
	if (m_flags->a_flag == 1)
	{
		if (argc == 2)
		{
			i = 0;
			ft_only_a(find_data, i);
		}
		else
		{
			i = 1;
			while (i < argc && ft_check_flags(argc, argv) == 0)
				i++;
			i++;
			ft_multi_a(argv, i, find_data);
		}
	}
}
