/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:14:28 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/13 15:32:29 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_lflag(int argc,char **argv, t_flags *m_flags, d_list *man_data)
{
	printf("%s\n", man_data->strings[1]);
	int i;

	i = 1;
	while (i < argc && ft_check_flags(argc, argv) == 0)
	{
		i++;
	}
	i++;
	
//	printf("%i >>%s\n", i, argv[i]);
	ft_verflag(argv, m_flags);
	if (m_flags->l_flag == 1)
	{
		printf("L flag is true");
		if (argc >= 2)
		{
			struct stat fileinfo;
			struct passwd *pwd;
			struct group *gwd;
			int j;

			j = 0;
			//ft_currentdir(argc, argv, man_data);
			while(/*man_data->strings[j]*/argv[i] != NULL/* && i < argc*/)
			{
			//	printf("%s\n", man_data->strings[j]);
				if (stat(/*man_data->strings[j]*/argv[i], &fileinfo) < 0)
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
