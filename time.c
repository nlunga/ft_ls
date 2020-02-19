/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <nlunga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:07:59 by nlunga            #+#    #+#             */
/*   Updated: 2020/02/17 13:33:24 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void	run_other(char **path, int i, t_dir *data)
{
	while (path[i] != NULL)
	{
		if (!ft_isdir(path[i]))
		{
			ft_opendirtime(path[i], data);
			ft_displaytime(data, ft_structlen(data));
			ft_putendl(path[i]);
		}
		else
		{
			ft_putendl(path[i]);
		}
		i++;
	}
}

void			ft_timeflag(int argc, char **path, t_flags *mflag, t_dir *data)
{
	int		i;

	i = 1;
	while (i < argc && ft_check_flags(argc, path) == 0)
		i++;
	i++;
	ft_verflag(argc, path, mflag);
	if (mflag->t_flag == 1)
	{
		if (i == 2 && path[i] == NULL)
		{
			ft_opendirtime(".", data);
			ft_displaytime(data, ft_structlen(data));
		}
		else
		{
			run_other(path, i, data);
		}
	}
}
