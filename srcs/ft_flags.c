/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <nlunga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:59:52 by nlunga            #+#    #+#             */
/*   Updated: 2020/02/07 14:41:07 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"
#include <stdio.h>

void	ft_lflag(char **path, t_flags *mflag, t_dir *data)
{
	int			i;
	int			j;
	struct stat	buf;

	i = 0;
	while (ft_check_flags(&path[i]))
		i++;
	i++;
	ft_verflag(path, mflag);
	if (mflag->l_flag == 1)
	{
		if (i == 2 && path[i] == NULL)
		{
			j = 0;
			ft_opendirsorted(".", data);
			while (data[j].name != NULL)
			{
				if (lstat(data[j].name, &buf) < 0)
						return ;
				ft_perm(buf);
				ft_putnbr_add(buf.st_nlink, '\t');
				ft_getid(buf);
				ft_putnbr_add(buf.st_size, '\t');
				ft_m_time(data[j].name);
				printf("%s\n", data[j].name);
				j++;
			}
		}else
		{
			j = 0;
			while (path[i] != NULL)
			{
				if (ft_isdir(path[i]))
				{
					ft_putstr_add(path[i], ':');
					ft_putchar('\n');
					ft_opendirsorted(path[i], data);
					while (data[j].name != NULL)
					{
						data[j].path = ft_addpath(ft_strjoin("./",path[i]), data[j].name);
						if (lstat(data[j].path, &buf) < 0){
							perror(data[j].path);
							return ;
						}
						ft_perm(buf);
						ft_putnbr_add(buf.st_nlink, '\t');
						ft_getid(buf);
						ft_putnbr_add(buf.st_size, '\t');
						ft_m_time(data[j].path);
						printf("%s\n", data[j].name);
						j++;
					}
					ft_putchar('\n');
				}else
				{
					if (lstat(path[i], &buf) < 0)
						return ;
					ft_perm(buf);
					ft_putnbr_add(buf.st_nlink, '\t');
					ft_getid(buf);
					ft_putnbr_add(buf.st_size, '\t');
					ft_m_time(path[i]);
					printf("%s\n", path[i]);
				}
				
				i++;
			}	
		}
		
	}
}