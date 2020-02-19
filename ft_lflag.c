/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:14:28 by nlunga            #+#    #+#             */
/*   Updated: 2020/02/19 11:48:16 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	int	first(d_list *f)
{
	int			j;
	struct stat	fileinfo;

	j = 0;
	ft_otherdir(".", f);
	while (f->dr[j] != NULL)
	{
		if (lstat(f->dr[j], &fileinfo) < 0)
			return (1);
		da_perm(fileinfo);
		ft_putnbr_add(fileinfo.st_nlink, '\t');
		ft_getuid(fileinfo);
		ft_getgid(fileinfo);
		ft_putchar(' ');
		ft_putnbr_add(fileinfo.st_size, '\t');
		ft_putstr("   ");
		ft_m_time(f->dr[j]);
		printf("%s\n", f->dr[j]);
		ft_strdel(&f->dr[j]);
		j++;
	}
	return (0);
}

static	int	second(char **argv, d_list *f, int i)
{
	int			d;
	struct stat	fileinfo;

	d = 0;
	ft_putstr(argv[i]);
	ft_putendl(":\n");
	ft_otherdir(argv[i], f);
	while (f->dr[d] != NULL)
	{
		if (lstat(ft_strjoin(f->path, f->dr[d]), &fileinfo) < 0)
		{
			return (1);
		}
		da_perm(fileinfo);
		printf("%hu ", fileinfo.st_nlink);
		ft_getuid(fileinfo);
		ft_getgid(fileinfo);
		printf(" %lld ", fileinfo.st_size);
		ft_m_time(f->dr[d]);
		printf("%s\n", f->dr[d]);
		ft_strdel(&f->dr[d]);
		d++;
	}
	return (0);
}

static	int	third(char **argv, int i)
{
	struct stat	fileinfo;

	if (lstat(argv[i], &fileinfo) < 0)
		return (1);
	da_perm(fileinfo);
	printf("%hu ", fileinfo.st_nlink);
	ft_getuid(fileinfo);
	ft_getgid(fileinfo);
	printf(" %lld ", fileinfo.st_size);
	ft_m_time(argv[i]);
	printf("%s\n", argv[i]);
	return (0);
}

int			ft_lflag(int argc, char **argv, t_flags *mf, d_list *f)
{
	int i;
	int d;

	i = 1;
	while (i < argc && ft_check_flags(argc, argv) == 0)
	{
		i++;
	}
	i++;
	ft_verflag(argc, argv, mf);
	if (mf->l_flag == 1)
	{
		if (argc == 2)
			first(f);
		else if (argc != 2)
		{
			ft_bubblesort(argv);
			while (argv[i] != NULL)
			{
				f->path = ft_strdup(ft_strjoin(argv[i], "/"));
				d = 0;
				if (ft_isdir(argv[i]) == 1)
					second(argv, f, i);
				else
				{
					third(argv, i);
				}
				ft_strdel(&f->path);
				printf("\n");
				i++;
			}
		}
		else
			return (0);
	}
	return (0);
}
