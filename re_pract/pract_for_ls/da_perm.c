/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   da_perm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:03:24 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/22 16:34:16 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	da_perm(struct stat fileinfo)
{
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
}
