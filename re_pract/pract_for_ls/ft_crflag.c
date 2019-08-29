/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:31:34 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/29 16:16:29 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_crflag(int argc, char **argv, t_flags *m_flags, d_list *find_data)
{
	ft_verflag(argv, m_flags);
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
			ft_currentdir(find_data);
			while (find_data->strings[i] != NULL)
			{
				if (ft_isdir(find_data->strings[i]))
				{
					find_data->big_r[c] = ft_strdup(find_data->strings[i]);
					c++;
				}
				ft_putendl(find_data->strings[i]);
				ft_strdel(&find_data->strings[i]);
				i++;
			}
			ft_putendl(" ");
			ft_putendl(find_data->big_r[0]);
			ft_putendl(find_data->big_r[1]);
			ft_putendl(find_data->big_r[2]);
			ft_putendl(find_data->big_r[3]);
			ft_putendl(find_data->big_r[4]);
			//ft_putchar(' ');
			/*while (find_data->big_r[d] != NULL)
			{
				ft_otherdir(find_data->big_r[d], find_data);
				ft_crflag(argc, argv, m_flags, find_data);
				d++;
			}*/
		}
	}
}
