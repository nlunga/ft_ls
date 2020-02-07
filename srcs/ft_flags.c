/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <nlunga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:59:52 by nlunga            #+#    #+#             */
/*   Updated: 2020/02/07 09:42:28 by nlunga           ###   ########.fr       */
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
			// j = 0; This is the original
			while (path[i] != NULL)
			{
				printf("This is a file/directory name: %s\n\n", path[i]);
				j = 0;
				//data[j]->path = ft_addpath("./", path[i]);
				// k = 0; This is The original
				// printf("This  is path %s ", path[i]);
				if (ft_isdir(path[i]))
				{
					printf("hi %s\n",path[i]);
					k = 0;
					ft_opendir(path[i], data);
					data[j].path = ft_addpath(path[i], data[k].name);
					while (data[k].name != NULL)
					{
						// printf("\nThis is the name %s", data[k].name);
						// printf("\n%d", k);
						// if (lstat(data[j].path, &buf) < 0) // Original I might wanna check it for debugging
						if (lstat(data[j].name, &buf) < 0)
							return ;
						// return (1);
						// printf("\nThis is j: %d\n", j);
						// ft_perm(buf);
						// ft_getid(buf);
						// printf("%s ", data[j].path);
						// ft_m_time(data[k].name);
						k++;
					}
					j++;
				}else
				{
					if (lstat(path[i], &buf) < 0)
						return ;
					// return (1);
					ft_perm(buf);
					ft_getid(buf);
					printf("%s ", data[j].path);
					ft_m_time(data[k].name);
				}
				
				i++;
			}	
		}
		
	}
}


// If there is a -l flag enter the code block
// Scan until you find the end of the flags
// Check if the next options is a directory or if it is a file
// If it is a file apply the stats to the file
// If it is a directory open the directory and apply the stats to the files in the directory
