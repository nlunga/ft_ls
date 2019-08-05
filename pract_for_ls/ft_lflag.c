/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:14:28 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/05 16:56:13 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_lflag(int argc,char **argv, t_flags *m_flags)
{
	int i;

	i = 1;
/*	while (argv[i])
	{
		if (ft_check_flags(argc, argv) == 0)
			break;
		i++;
	}*/
//	i--;
	while (i < argc && ft_check_flags(argc, argv) == 0)
	{
		i++;
	}
	i++;
	printf("%i >>%s\n", i, argv[i]);
	ft_verflag(argv, m_flags);
	if (m_flags->l_flag == 1)
	{
		struct stat fileinfo;
		if (stat(argv[i], &fileinfo) < 0)
			return (1);		
		printf( (S_ISDIR(fileinfo.st_mode)) ? "d" : "-");
		printf( (fileinfo.st_mode & S_IRUSR) ? "r" : " -");
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
		printf(" %lld ",fileinfo.st_size);
		ft_m_time(argv[i]);
		printf("%s\n", argv[i]);
	}
	return (0);
}
