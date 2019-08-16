/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 09:55:15 by nlunga            #+#    #+#             */
/*   Updated: 2019/07/26 16:33:59 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_conflags(int argc, char **argv)
{
	struct s_flags m_flags;
	int	i;
	int j;
	
	i = 0;
	if (ft_check_flags(argc, argv) == 1)
	{
		i = 1;
		j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] == 'l')
				m_flags.l_flag = 1;
			else if (argv[i][j] == 'a')
				m_flags.a_flag = 2;
			else if (argv[i][j] == 'r')
				m_flags.r_flag = 4;
			else if (argv[i][j] == 't')
				m_flags.t_flag = 8;
			else if (argv[i][j] == 'R')
				m_flags.cr_flag = 16;
			j++;
		}
	}		
	return (0);
}

/*
while (argv[i][j])
{
		if (argv[i][j] == 'l')
			m_flags.l_flag = 1 << 0;
		else if (argv[i][j] == 'a')
			m_flags.a_flag = 1 << 1;
		else if (argv[i][j] == 'r')
			m_flags.r_flag = 1 << 2;
		else if (argv[i][j] == 't')
			m_flags.t_flag = 1 << 3;
		else if (argv[i][j] == 'R')
			m_flags.cr_flag = 1 << 4;
		j++;
}
*/
