/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:35:18 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/30 13:12:03 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

int	ft_check_flags(char **str)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (str[i][0] != '-')
			break ;
		if (str[i][0] == '-')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_isdir(char *path)
{
	struct stat		buf;

	stat(path, &buf);
	if (S_ISDIR(buf.st_mode))
		return (1);
	else
		return (0);
}

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

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}
