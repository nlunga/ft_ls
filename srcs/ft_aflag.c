/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 09:02:02 by nlunga            #+#    #+#             */
/*   Updated: 2020/02/13 09:02:18 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

void	ft_multi_a(char **argv, int i, int n, t_dir *find_data)
{
	int	d;

	while (argv[i] != NULL)
	{
		d = 0;
		find_data->path = ft_strdup(ft_strjoin(argv[i], "/"));
		ft_putstr(argv[i]);
		ft_putendl(":");
		// ft_putendl(find_data->strings[d]);
		// ft_aotherdir(find_data->path, find_data);
		// while (find_data->strings[d] != NULL)
		// {
		// 	ft_putendl(find_data->strings[d]);
		// 	ft_strdel(&find_data->strings[d]);
		// 	d++;
		// }
        ft_bubblesort(find_data);
        while (d < n)
        {
            ft_putendl(find_data[d].name);
            ft_strdel(&find_data[d].name);
            d++;
        }
		ft_putendl(" ");
		i++;
	}
}

// void	ft_only_a(t_dir *find_data, int i)
// {
// 	ft_aotherdir(".", find_data);
// 	while (find_data->strings[i] != NULL)
// 	{
// 		ft_putendl(find_data->strings[i]);
// 		ft_strdel(&find_data->strings[i]);
// 		i++;
// 	}
// }

void	ft_aflag(int argc, char **argv, t_flags *m_flags, t_dir *find_data)
{
	int	i;

	i = 1;
	while (i < argc && ft_check_flags(argv) == 0)
		i++;
	i++;
	ft_verflag(argv, m_flags);
	if (m_flags->a_flag == 1)
	{
		if (argc == 2)
		{
			i = 0;
            ft_opendir(".", find_data);
			ft_displayall(find_data, ft_structlen(find_data));
		}
		else
		{
			i = 1;
			while (i < argc && ft_check_flags(argv) == 0)
				i++;
			i++;
			ft_multi_a(argv, i, ft_structlen(find_data), find_data);
		}
	}
}