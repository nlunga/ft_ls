/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:43:53 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/30 13:10:53 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

void	ft_perm(struct stat fileinfo)
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

void	ft_getid(struct stat buf)
{
	struct group	*group;
	struct passwd	*pwd;

	pwd = getpwuid(buf.st_uid);
	group = getgrgid(buf.st_gid);
	ft_putstr_add(pwd->pw_name, ' ');
	ft_putstr_add(group->gr_name, ' ');
}
