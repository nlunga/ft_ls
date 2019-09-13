/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:35:35 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/13 22:11:18 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_rflag(int argc, char **argv, t_flags *m_flags, d_list *find_data)
{
	ft_verflag(argc, argv, m_flags);
	if (m_flags->r_flag == 1)
	{
		if (argc == 2)
		{
			int i;

			i = 0;
			ft_otherdir(".", find_data);
			while (find_data->dr[i] != NULL)
				i++;
			while (i >= 0)
			{
				ft_putendl(find_data->dr[i]);
				ft_strdel(&find_data->dr[i]);
				i--;
			}
		}
		else
		{
			int i;
			int j;

			j = 2;
			i = 0;
			while (argv[j])
			{
				ft_putstr("\n");
				ft_putstr(argv[j]);
				ft_putendl(":");
				ft_otherdir(argv[j], find_data);
				while (find_data->dr[i] != NULL)
					i++;
				while (i >= 0)
				{
					ft_putendl(find_data->dr[i]);
					ft_strdel(&find_data->dr[i]);
					i--;
				}
				j++;
			}

		}
	}
}
