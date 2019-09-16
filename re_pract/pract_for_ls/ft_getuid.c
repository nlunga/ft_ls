/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getuid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:13:23 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/23 08:36:01 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_getuid(struct stat fileinfo)
{
	struct passwd	*pwd;

	if ((pwd = getpwuid(fileinfo.st_uid)))
	{
		ft_putstr_add(pwd->pw_name, ' ');
	}
}
