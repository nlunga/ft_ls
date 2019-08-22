/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:14:28 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/22 16:34:12 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_lflag(int argc,char **argv, t_flags *m_flags, d_list *find_data)
{
	int i;
	int d;

	i = 1;
	while (i < argc && ft_check_flags(argc, argv) == 0)
	{
		i++;
	}
	i++;
	
	//printf("%i >>%s\n", i, argv[i]);
	ft_verflag(argv, m_flags);
	if (m_flags->l_flag == 1)
	{
		struct stat		fileinfo;
		if (argc == 2/* && (ft_strcmp(argv[1], "-l")) == 0*/)
		{
			int j;

			j = 0;
			ft_currentdir(find_data);
			while(find_data->strings[j] != NULL)
			{
				if (lstat(find_data->strings[j], &fileinfo) < 0)
					return (1);
				da_perm(fileinfo);
				printf("%d ",fileinfo.st_nlink);
				ft_getuid(fileinfo);
				ft_getgid(fileinfo);
				printf(" %lld ",fileinfo.st_size);
				ft_m_time(find_data->strings[j]);
				printf("%s\n", find_data->strings[j]);
				j++;
			}
		}
		else if (argc != 2)
		{
			while (argv[i] != NULL)
			{
				find_data->path = ft_strdup(ft_strjoin(argv[i], "/"));
				d = 0;
				if (ft_isdir(argv[i]) == 1)
				{
					printf("%s:\n", argv[i]);
					ft_otherdir(argv[i], find_data);
				
					while(find_data->dir_strings[d] != NULL)
					{
						if (lstat(ft_strjoin(find_data->path,find_data->dir_strings[d]), &fileinfo) < 0)
						{
							return (1);
						}
						da_perm(fileinfo);
						printf("%d ",fileinfo.st_nlink);
						ft_getuid(fileinfo);
						ft_getgid(fileinfo);
						printf(" %lld ",fileinfo.st_size);
						ft_m_time(find_data->dir_strings[d]);
						printf("%s\n", find_data->dir_strings[d]);
						d++;
					}
				}
				else
				{
					if (lstat(argv[i], &fileinfo) < 0)
						return (1);
					da_perm(fileinfo);
					printf("%d ",fileinfo.st_nlink);
					ft_getuid(fileinfo);
					ft_getgid(fileinfo);
					printf(" %lld ",fileinfo.st_size);
					ft_m_time(argv[i]);
					printf("%s\n", argv[i]);
				}
				printf("\n");
				i++;
			}
		}
		else
			return (0); 
	}
	return (0);
}
