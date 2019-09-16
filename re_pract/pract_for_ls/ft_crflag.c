/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:26:17 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/16 16:26:30 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_recurstore(char **arr, d_list *find_data)
{
	int i;
	int x = 0;
	static int c = 0;

	i = 0;
//	ft_otherdir(arr, find_data);
	while (arr[i] != NULL)
	{
		//printf("arr[%i]: %s\n", i, arr[i]);
		if (ft_isdir(arr[i]))
		{
			//printf("-----------------arr[%d] has passed is_dir: %s\n", i,  arr[i]);
			find_data->big_r[c] = ft_strdup(arr[i]);
			c++;
		}
		ft_putendl(arr[i]);
		ft_strdel(&arr[i]);
		i++;
	}
	ft_putendl(" ");
	sleep(5);
	//printf("%s\n", find_data->big_r[x]);
	while (find_data->big_r[x] != NULL)
	{
		ft_recurstore(&find_data->big_r[x], find_data);
		ft_strdel(&find_data->big_r[x]);
		x++;
	}
}

void	ft_crflag(int argc, char **path, t_flags *m_flags, d_list *find_data)
{
	int x = 0;

	ft_verflag(argc, path, m_flags);
	if (m_flags->cr_flag)
	{
		if (argc == 2)
		{
		//	int i;

		//	i = 0;
			ft_otherdir(".", find_data);
			ft_recurstore(find_data->dr, find_data);
		}			
	}
	printf("%s\n", find_data->big_r[x]);
	while (find_data->big_r[x] != NULL)
	{
		printf("directories collected: %s\n", find_data->big_r[x]);
		x++;
	}
}
