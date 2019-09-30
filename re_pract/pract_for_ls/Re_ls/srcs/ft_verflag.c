/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:05:12 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/30 13:53:30 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

void	ft_assign(char **str, t_flags *m_flags)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 1;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == 'l')
				m_flags->l_flag = 1;
			else if (str[i][j] == 'a')
				m_flags->a_flag = 1;
			else if (str[i][j] == 'r')
				m_flags->r_flag = 1;
			else if (str[i][j] == 't')
				m_flags->t_flag = 1;
			else if (str[i][j] == 'R')
				m_flags->cr_flag = 1;
			j++;
		}
		i++;
	}
}

void	ft_verflag(char **str, t_flags *m_flags)
{
	m_flags->l_flag = 0;
	m_flags->a_flag = 0;
	m_flags->r_flag = 0;
	m_flags->t_flag = 0;
	m_flags->cr_flag = 0;

	if (ft_check_flags(str))
		ft_assign(str, m_flags);
}
