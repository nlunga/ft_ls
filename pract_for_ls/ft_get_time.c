/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:35:41 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/05 14:27:27 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_m_time(const char *path)
{
	struct stat da_mtime;
	char		temp[13];
	char		da_time[25];
	int			i;
	int			k;
	
	stat(path, &da_mtime);
	ft_strcpy(da_time, ctime(&da_mtime.st_mtime));
	i = 4;
	k = 0;
	while (i < 16)
	{
		temp[k] = da_time[i];
		k++;
		i++;
	}
	temp[k] = '\0';
	printf("%s ", temp);
}
