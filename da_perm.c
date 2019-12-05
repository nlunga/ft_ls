/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   da_perm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:03:24 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/16 16:26:28 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	da_perm(struct stat fileinfo)
{
	ft_putstr((S_ISDIR(fileinfo.st_mode)) ? "d" : "-");
	ft_putstr((fileinfo.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((fileinfo.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((fileinfo.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((fileinfo.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((fileinfo.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((fileinfo.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((fileinfo.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((fileinfo.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((fileinfo.st_mode & S_IXOTH) ? "x" : "-");
	ft_putchar(' ');
}
