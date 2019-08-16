/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:14:28 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/16 20:47:20 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_lflag(int argc,char **argv, t_flags *m_flags, d_list *find_data)
{
	int i;

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
		printf("it is executing\n");
		if (argc == 2 && (ft_strcmp(argv[1], "-l")) == 0)
		{
			struct stat		fileinfo;
			struct passwd	*pwd;
			struct group	*gwd;
			int j;

			j = 0;
			ft_currentdir(find_data);
			while(find_data->strings[j] != NULL)
			{
				if (stat(find_data->strings[j], &fileinfo) < 0)
					return (1);
				printf( (S_ISDIR(fileinfo.st_mode)) ? "d" : "-");
				printf( (fileinfo.st_mode & S_IRUSR) ? "r" : "-");
				printf( (fileinfo.st_mode & S_IWUSR) ? "w" : "-");
				printf( (fileinfo.st_mode & S_IXUSR) ? "x" : "-");
				printf( (fileinfo.st_mode & S_IRGRP) ? "r" : "-");
				printf( (fileinfo.st_mode & S_IWGRP) ? "w" : "-");
				printf( (fileinfo.st_mode & S_IXGRP) ? "x" : "-");
				printf( (fileinfo.st_mode & S_IROTH) ? "r" : "-");
				printf( (fileinfo.st_mode & S_IWOTH) ? "w" : "-");
				printf( (fileinfo.st_mode & S_IXOTH) ? "x" : "-");
				printf(" ");
				printf("%d ",fileinfo.st_nlink);
				if ((pwd = getpwuid(fileinfo.st_uid)))
					printf("%s ",pwd->pw_name);
				if ((gwd = getgrgid(fileinfo.st_gid)))
					printf("%s ",gwd->gr_name);
				printf(" %lld ",fileinfo.st_size);
				ft_m_time(find_data->strings[j]);
				printf("%s\n", find_data->strings[j]);
				j++;
			}
		}
/*		else if (argc < 3)
		{
			struct stat		dirinfo;
			struct passwd	*pwd;
			struct group	*gwd;
			int d;

			d = 0;
			ft_otherdir(argv[i], find_data);
			while(find_data->strings[d] != NULL)
			{
				if (stat(find_data->dir_strings[d], &dirinfo) < 0)
					return (1);
				printf( (S_ISDIR(dirinfo.st_mode)) ? "d" : "-");
				printf( (dirinfo.st_mode & S_IRUSR) ? "r" : "-");
				printf( (dirinfo.st_mode & S_IWUSR) ? "w" : "-");
				printf( (dirinfo.st_mode & S_IXUSR) ? "x" : "-");
				printf( (dirinfo.st_mode & S_IRGRP) ? "r" : "-");
				printf( (dirinfo.st_mode & S_IWGRP) ? "w" : "-");
				printf( (dirinfo.st_mode & S_IXGRP) ? "x" : "-");
				printf( (dirinfo.st_mode & S_IROTH) ? "r" : "-");
				printf( (dirinfo.st_mode & S_IWOTH) ? "w" : "-");
				printf( (dirinfo.st_mode & S_IXOTH) ? "x" : "-");
				printf(" ");
				printf("%d ",dirinfo.st_nlink);
				if ((pwd = getpwuid(dirinfo.st_uid)))
					printf("%s ",pwd->pw_name);
				if ((gwd = getgrgid(dirinfo.st_gid)))
					printf("%s ",gwd->gr_name);
				printf(" %lld ",dirinfo.st_size);
				ft_m_time(find_data->dir_strings[d]);
				printf("%s\n", find_data->dir_strings[d]);
				d++;
			}
		}
		else
			return (0); */
	}
	return (0);
}
