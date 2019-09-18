/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:58:12 by nlunga            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/23 14:39:36 by nlunga           ###   ########.fr       */
=======
/*   Updated: 2019/09/13 22:13:19 by nlunga           ###   ########.fr       */
>>>>>>> b761845e4f8a3cb5a090ecaa31907f0ba8909537
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

void	ft_verflag(int argc, char **argv, t_flags *m_flags)
{
	int	i;
	int	j;
	m_flags->l_flag = 0;
	m_flags->a_flag = 0;
	m_flags->r_flag = 0;
	m_flags->t_flag = 0;
	m_flags->cr_flag = 0;
	
	i = 1;
	if (ft_check_flags(argc, argv))
	{
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
	}
	//return ; //(0);
}

void	do_flags(int argc, char **argv, t_flags *m_flags, d_list *find_data)
{
	int i;
	int c;

	i = 1;
	ft_verflag(argc, argv, m_flags);
	if (m_flags->l_flag == 1)
		ft_lflag(argc, argv, m_flags, find_data);
	if (m_flags->a_flag == 1)
		ft_aflag(argc, argv, m_flags, find_data);
	if (m_flags->r_flag == 1)
		ft_rflag(argc, argv, m_flags, find_data);
	if (m_flags->cr_flag == 1)
		ft_crflag(argc, argv, m_flags, find_data);
	if (m_flags->t_flag == 1)
		ft_tflag(".", find_data->dr, ft_arrlen(find_data->dr));
	if (!ft_check_flags(argc, argv))//else
	{
		c = 0;
		while (argv[i] != NULL)
		{
			ft_putstr(argv[i]);
			ft_putendl(":");
			ft_otherdir(argv[i], find_data);
			while (find_data->dr[c] != NULL)
			{
				ft_putendl(find_data->dr[c]);
				ft_strdel(&find_data->dr[c]);
				c++;
			}
			ft_putendl(" ");
			i++;
		}
	}
}
