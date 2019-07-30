/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:14:28 by nlunga            #+#    #+#             */
/*   Updated: 2019/07/30 16:40:53 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
int	ft_lflag(int argc, char **argv)
{
	if (!argc)
		exit(1);
	struct stat fileinfo;
	if(stat(argv[1],&fileinfo) < 0)
		return 1;
	printf("File Permissions: \n");
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
	printf("\n");
	return (0);
}
*/


//int	ft_lflag(/*int argc,*/ char **argv)
//{
//	ft_permissions(/*argc,*/ argv);
//	ft_putchar('\t');
//	return (0);
//}

int	ft_lflag(int argc,char **argv, t_flags *m_flags)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (ft_check_flags(argc, argv) == 0)
			break;
		i++;
	}
	i--;
	printf("%i >>%s\n", i, argv[i]);
	ft_verflag(argv, m_flags);
	if (m_flags->l_flag == 1)
	{
		struct stat fileinfo;
		if (stat(argv[i], &fileinfo) < 0)
			return (1);
		printf("File Permissions: \n");
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
		printf("\n");
	}
	return (0);
}
