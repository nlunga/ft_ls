/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <nlunga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:59:52 by nlunga            #+#    #+#             */
/*   Updated: 2020/02/03 15:15:39 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"
#include <stdio.h>

void	ft_lflag(char **path, t_flags *mflag, t_dir *data)
{
	int			i;
	int			j;
	int			k;
	struct stat	buf;

	i = 0;
	while (ft_check_flags(&path[i]))
		i++;
	// printf("%d\n", i);
	i++;
	// printf("%d\n", i);
	ft_verflag(path, mflag);
	if (mflag->l_flag == 1)
	{
		printf(">>>>> %s\n <<<<<", path[i]);
		j = 0;
		while (path[i] != NULL)
		{
			//data[j]->pathft_addpath(, path[i]);
			k = 0;
			printf("This  is path %s ", path[i]);
			if (ft_isdir(path[i]) && (mflag->a_flag == 0))
			{
				ft_opendir(path[i], data);
				data[j].path = ft_addpath(path[i], data[k].name);
				while (data[k].name != NULL)
				{
					
					printf("\n%d\n", k);
					if (lstat(data[j].path, &buf) < 0)
						ft_putendl("lstat: FAILURE");
				//		return (1);
					ft_perm(buf);
					ft_getid(buf);
					// printf("%s ", data[j].path);
					ft_m_time(data[k].name);
					k++;
				}
				j++;
			}
			i++;
		}
	}
}
