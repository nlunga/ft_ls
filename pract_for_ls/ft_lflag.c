/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:14:28 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/17 10:30:35 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_lflag(int argc,char **argv, t_flags *m_flags/*, d_list *find_data*/)
{
	int i;
 	d_list *find_data;

	i = 1;
	find_data = (d_list *)malloc(sizeof(d_list));

	while (i < argc && ft_check_flags(argc, argv) == 0)
	{
		i++;
	}
	i++;
	
	printf("%i >>%s\n", i, argv[i]);
	ft_verflag(argv, m_flags);
	if (m_flags->l_flag == 1)
	{
		if (argc == 2)
		{
			struct stat fileinfo;
			struct passwd *pwd;
			struct group *gwd;
			int j;

			j = 0;
			ft_currentdir(argc, argv, find_data);
			printf("%s\n", find_data->strings[0]);
			while(argv[i] != NULL)
			{
				//if (ft_isdir(&argv[i]) == 1)
				if (stat(ft_strcat("./", argv[i]), &fileinfo) < 0)
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
				ft_m_time(argv[i]);
				printf("%s\n", argv[i]);
				j++;
				i++;
			}
		}
		else if (argc < 2)
		{

		}
	}
	return (0);
}
