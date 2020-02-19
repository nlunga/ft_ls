/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:35:35 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/13 22:11:18 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void	run_other(char **path, int i, t_dir *data)
{
	while (path[i] != NULL)
	{
		if (ft_isdir(path[i]))
		{
			ft_opendir(path[i], data);
			ft_displayrev(data, ft_structlen(data));
		}
		else
		{
			ft_putendl(path[i]);
		}
		i++;
	}
}

void			ft_rflag(int argc, char **argv, t_flags *mflag, t_dir *data)
{
	int		i;

	i = 1;
	while (i < argc && ft_check_flags(argc, argv) == 0)
		i++;
	i++;
	ft_verflag(argc, argv, mflag);
	if (mflag->r_flag == 1)
	{
		if (i == 2 && argv[i] == NULL)
		{
			ft_opendir(".", data);
			ft_displayrev(data, ft_structlen(data));
		}
		else
		{
			run_other(argv, i, data);
		}
	}
}
