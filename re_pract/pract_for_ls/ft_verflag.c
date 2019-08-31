/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:58:12 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/31 07:58:34 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_verflag(char **argv, t_flags *m_flags)
{
	int	i;
	int	j;
	m_flags->l_flag = 0;
	m_flags->a_flag = 0;
	m_flags->r_flag = 0;
	m_flags->t_flag = 0;
	m_flags->cr_flag = 0;
	
	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == 'l')
				m_flags->l_flag = 1;
			else if (argv[i][j] == 'a')
				m_flags->a_flag = 1;
			else if (argv[i][j] == 'r')
				m_flags->r_flag = 1;
			else if (argv[i][j] == 't')
				m_flags->t_flag = 1;
			else if (argv[i][j] == 'R')
				m_flags->cr_flag = 1;
			j++;
		}
		i++;
	}
	//return ; //(0);
}

void	do_flags(int argc, char **argv, t_flags *m_flags, d_list *find_data)
{
	int i;
	int c;

	i = 1;
	ft_verflag(argv, m_flags);
	if (ft_check_flags(argc, argv) == 1)
	{
		if (m_flags->l_flag)
			ft_lflag(argc, argv, m_flags, find_data);
		if (m_flags->a_flag)
			ft_aflag(argc, argv, m_flags, find_data);
		if (m_flags->r_flag)
			ft_rflag(argc, argv, m_flags, find_data);
	}
	else
	{
		c = 0;
		while (argv[i] != NULL)
		{
			ft_putstr(argv[i]);
			ft_putendl(":");
			ft_otherdir(argv[i], find_data);
			while (find_data->dir_strings[c] != NULL)
			{
				ft_putendl(find_data->dir_strings[c]);
				ft_strdel(&find_data->dir_strings[c]);
				c++;
			}
			ft_putendl(" ");
			i++;
		}
	}
}
