/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:10:26 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/12 13:21:06 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*void	ft_store_time(const char *path, d_list *find_data, int x)
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

	//find_data->mtime[x] = ft_strdup(temp);
	find_data->mtime[x] = ft_strdup(ft_strjoin(temp, path));

	//find_data->mfile[x] = ft_strdup(path);
}*/
/*void	bubble_sort(int arr[], int n) 
{
	int	i;
	int	j;
	int	swapped;
	i = 0;
	while (i < n-1)
	{
		swapped = 0;
		j = 0;
		while (j < n-i-1)
		{
			if (arr[j] > arr[j+1])
			{
				ft_swap(&arr[j], &arr[j+1]);
				swapped = 1;
			}
			j++;
		}

     // IF no two elements were swapped by inner loop, then break
		if (swapped == 0)
			break;
		i++;
	}
}*/

void	ft_store_time(const char *path, d_list *find_data, int x)
{
	struct stat		da_mtime;
	//char			*str;
	//int			i;

	stat(path, &da_mtime);
	//find_data->time[x] = da_mtime.st_mtime;
	find_data->mfile[x] = ft_strdup(ft_itoa(da_mtime.st_mtime));
//	find_data->mtime[x] = ft_strdup(ft_itoa(da_mtime.st_mtime));
	find_data->mtime[x] = ft_strdup(ft_strjoin(find_data->mfile[x], path));
	ft_strdel(&find_data->mfile[x]);
	/*printf("%ld\n", da_mtime.st_mtime);
	printf("%s\n", find_data->mtime[x]);*/
	//find_data->mtime[x] = ft_strdup(ft_itoa(find_data->time[x]));
}

void	bubble_sort(int arr[], int n) 
{
	int	i;
	int	j;
	int	swapped;
	i = 0;
	while (i < n-1)
	{
		swapped = 0;
		j = 0;
		while (j < n-i-1)
		{
			if (arr[j] > arr[j+1])
			{
				ft_swap(&arr[j], &arr[j+1]);
				swapped = 1;
			}
			j++;
		}

     // IF no two elements were swapped by inner loop, then break
		if (swapped == 0)
			break;
		i++;
	}
}

void	ft_tsort(char **path, d_list *find_data)
{
	int	i;
	int x;

	i = 0;
	x = 0;
	while (path[i] != NULL)
	{
		ft_store_time(path[i], find_data, x);
		i++;
		if (find_data->mtime[x] != NULL)
			x++;
	}
	ft_bubblesort(find_data->mtime);
	bubble_sort(find_data->time, x);
}

/*void	bubble_sort(int arr[], int n) 
{
	int	i;
	int	j;
	int	swapped;
	i = 0;
	while (i < n-1)
	{
		swapped = 0;
		j = 0;
		while (j < n-i-1)
		{
			if (arr[j] > arr[j+1])
			{
				ft_swap(&arr[j], &arr[j+1]);
				swapped = 1;
			}
			j++;
		}

     // IF no two elements were swapped by inner loop, then break
		if (swapped == 0)
			break;
		i++;
	}
}
*/
void	ft_tflag(int argc, char **argv, d_list *find_data)
{
	int i;

	i = 0;	
	if (argc == 2)
	{
		ft_otherdir(".", find_data);
		ft_tsort(find_data->dir_strings, find_data);
	//	ft_store_time(find_data->dir_strings[1], find_data, 0);
	//	printf("argv: %s, find_data: %s\n", argv[0], find_data->mtime[0]);
		while (find_data->dir_strings[i] != NULL && argv)
		{
			printf("%s\n", find_data->mtime[i]);
			printf("%d\n", find_data->time[i]);
//			ft_putendl(ft_tsort(find_data->dir_strings, find_data));
			i++;
		}
		ft_strdel(find_data->mtime);
	}
}
