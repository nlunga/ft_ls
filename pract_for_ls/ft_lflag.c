/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:14:28 by nlunga            #+#    #+#             */
/*   Updated: 2019/07/29 12:44:05 by nlunga           ###   ########.fr       */
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


int	ft_lflag(int argc, char **argv)
{
	ft_permissions(/*argc,*/ argv);
	ft_putchar('\t');
	return (0);
}
