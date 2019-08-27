/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:35:35 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/27 12:04:08 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_rflag(char **argv, t_flags *m_flags, d_list *find_data)
{
	ft_verflag(argv, m_flags);
	if (m_flags->r_flag == 1)
	{
		if (!argv[2])
		{
			int i;

			i = 0;
			ft_currentdir(find_data);
			while (find_data->strings[i] != NULL)
				i++;
			while (i >= 0)
				ft_putendl(find_data->strings[i--]);
		}
		else
		{
			int i;
			int j;

			j = 2;
			while (argv[j])
			{
				ft_otherdir(argv[j], find_data);
				i = 0;
				while (find_data->dir_strings[i] != NULL)
					i++;
				while (i >= 0)
					ft_putendl(find_data->dir_strings[i--]);
				j++;
			}

		}
	}
}
