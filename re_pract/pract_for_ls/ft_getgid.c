/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getgid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:21:11 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/23 08:35:09 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_getgid(struct stat fileinfo)
{
	struct group	*gwd;

	if ((gwd = getgrgid(fileinfo.st_gid)))
	{
		ft_putstr_add(gwd->gr_name, ' ');
	}
}
