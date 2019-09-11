/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:10:26 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/11 15:53:20 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_store_time(const char *path, d_list *find_data, int x)
{
	struct stat da_mtime;
	char		temp[13];
	char		da_time[25];
	int			i;
	int			j;
	int			k;

	stat(path, &da_mtime);
	ft_strcpy(da_time, ctime(&da_mtime.st_mtime));
	i = 4;
	k = 0;
	j = 0;
	while (i < 16)
	{
		temp[k] = da_time[i];
		k++;
		i++;
	}
	temp[k] = '\0';

	find_data->mtime[x] = ft_strdup(temp);
	//find_data->mtime = ft_strdup(temp)
	//printf("%s ", temp);
//	return (temp);
}

/*
void	ft_tsort(int argc, char **argv, t_flags *m_flags, d_list *find_data)
{
	int i;
	int j;

	if (argc == 2)
	{
		ft_otherdir(".", find_data);
		i = 0;
		while (find_data->dir_strings[i] != NULL)
		{
			find_data->mtime[i] = ft_strdup(ft_store_time(find_data->dir_strings[i]));
			i++;
		}
		ft_bubblesort(find_data->mtime);
	}
	else
	{
		j = 0;
		i = 0;
		while (argv[j] != NULL)
		{
			ft_otherdir(argv[j], find_data);
			//i = 0;
			while (find_data->dir_strings[i] != NULL)
			{
				find_data->mtime[i] = ft_strdup(ft_store_time(find_data->dir_strings[i]));
				i++;
			}
			ft_bubblesort(find_data->mtime);
			j++;
		}
	}
}
*/
void	ft_tsort(char **path, d_list *find_data)
{
	int	i;
	int x;

	i = 0;
	x = 0;
	while (path[i] != NULL)
	{
		ft_store_time(path[i], find_data, x);
//		find_data->mtime[i] = ft_strdup(ft_store_time(path[i]));
		i++;
		if (find_data->mtime[x] != NULL)
			x++;
	}
	ft_bubblesort(find_data->mtime);
}

void	ft_tflag(int argc, char **argv, d_list *find_data)
{
	int i;
//	char *arr[1024];

	i = 0;	
	if (argc == 2)
	{
		ft_otherdir(".", find_data);
//		arr = ft_tsort(find_data->dir_strings, find_data);
		printf("argv: %s, find_data: %s\n", argv[0], find_data->mtime[0]);
		/*		while (find_data->dir_strings[i] && argv)
		{
			printf("%s\n", find_data->mtime[i]);
//			ft_putendl(ft_tsort(find_data->dir_strings, find_data));
//			i++;
		}*/
	}
}
