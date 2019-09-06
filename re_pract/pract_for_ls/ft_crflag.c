/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:26:17 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/06 16:02:15 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_recurstore(char **arr, d_list *find_data)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (arr[i] != NULL)
	{
		if (ft_isdir(arr[i]))
			find_data->big_r[c++] = ft_strdup(arr[i]);
		ft_putendl(arr[i]);
		i++;
	}
	//c = 0;
	ft_putendl(" ");
	ft_recurstore(find_data->big_r, find_data);
	
//	while (find_data->big_r[c])
//		ft_putendl(find_data->big_r[c++]);

}

void	ft_crflag(int argc, char **path, t_flags *m_flags, d_list *find_data)
{
	ft_verflag(argc, path, m_flags);
	if (m_flags->cr_flag)
	{
		if (argc == 2)
		{
			int i;

			i = 0;
			ft_otherdir(".", find_data);
			ft_recurstore(find_data->dir_strings, find_data);
		}			
	}
}
