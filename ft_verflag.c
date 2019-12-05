/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:58:12 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/15 11:47:12 by nlunga           ###   ########.fr       */
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
