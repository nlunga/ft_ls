/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:14:28 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/17 10:30:26 by nlunga           ###   ########.fr       */
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
	//	printf("it is executing\n");
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
		else if (argc > 2)
		{
			printf("1 >> it is executing\n");
			struct stat		dirinfo;
			struct passwd	*nwd;
			struct group	*mwd;
//			int d;

			//d = 0;
			printf("%s\n", argv[i]);
			while (argv[i] != NULL)
			{
				d = 0;
				if (ft_isdir(argv[i]) == 1)
				{
					ft_otherdir(argv[i], find_data);
				
					//printf("%s\n", find_data->dir_strings[10]);
					//printf("%s\n", find_data->dir_strings[d]);
					//printf("2 >> it is executing\n");
				//	d = 0;
					while(find_data->dir_strings[d] != NULL)
					{
						printf("3 >> it is executing\n");
						printf("---------%s\n", find_data->dir_strings[d]);
						if (stat(find_data->dir_strings[d], &dirinfo) < 0)
						{
							return (1);
						}
						//stat(find_data->dir_strings[d], &dirinfo);
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
						if ((nwd = getpwuid(dirinfo.st_uid)))
							printf("%s ",nwd->pw_name);
						if ((mwd = getgrgid(dirinfo.st_gid)))
							printf("%s ",mwd->gr_name);
						printf(" %lld ",dirinfo.st_size);
						ft_m_time(find_data->dir_strings[d]);
						printf("%s\n", find_data->dir_strings[d]);
						d++;
					}
				}
				else
				{
					if (stat(argv[i], &dirinfo) < 0)
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
					if ((nwd = getpwuid(dirinfo.st_uid)))
						printf("%s ",nwd->pw_name);
					if ((mwd = getgrgid(dirinfo.st_gid)))
						printf("%s ",mwd->gr_name);
					printf(" %lld ",dirinfo.st_size);
					ft_m_time(argv[i]);
					printf("%s\n", argv[i]);
				}
				i++;
			}
		}
		else
			return (0); 
	}
	return (0);
}
