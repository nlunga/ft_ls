/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getuid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:13:23 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/22 16:20:28 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_getuid(struct stat fileinfo)
{
	struct passwd	*pwd;

	if ((pwd = getpwuid(fileinfo.st_uid)))
		printf("%s ",pwd->pw_name);
}
