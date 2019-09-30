/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:59:52 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/30 13:45:19 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

void	ft_lflag(char **path, t_flags *mflag, t_dir *data)
{
	int			i;
	int			j;
	int			k;
	struct stat	buf;

	i = 0;
	while (ft_check_flags(path))
		i++;
	i++;
	ft_verflag(path, mflag);
	if (mflag->l_flag == 1)
	{
		printf(">>>>> %s\n <<<<<", path[i]);
		j = 0;
		while (path[i] != NULL)
		{
			//data[j]->pathft_addpath(, path[i]);
			k = 0;
			if (ft_isdir(path[i]))
			{
				ft_opendir(path[i], data);
				data[j]->path = ft_addpath(path[i], data[k]->name);
				while (data[k]->name != NULL)
				{
					if (lstat(data[j]->path, &buf) < 0)
						ft_putendl("lstat: FAILURE");
				//		return (1);
					ft_perm(buf);
					ft_getid(buf);
					ft_m_time(data[k]->name);
					k++;
				}
				j++;
			}
			i++;
		}
	}
}
