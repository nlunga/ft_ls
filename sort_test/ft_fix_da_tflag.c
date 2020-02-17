/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:10:26 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/14 00:42:29 by nlunga           ###   ########.fr       */
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

	lstat(path, &da_mtime);
	find_data->time[x] = da_mtime.st_mtime;
	find_data->mfile[x] = ft_strdup(ft_itoa(da_mtime.st_mtime));
//1111112222222	find_data->mfile[x] = ft_strdup(ft_itoa(da_mtime.st_mtimespec.tv_nsec));
//1111112222222	find_data->time[x] = da_mtime.st_mtimespec.tv_nsec;
/*	find_data->mfile[x] = ft_strdup(ft_itoa(da_mtime.st_mtim));
	find_data->time[x] = da_mtime.st_mtim;*/
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
//	ft_bubblesort(find_data->mtime);
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

int    ft_st_time(char *path, char *path1)
{
    struct stat buf;
    struct stat buf1;
    //ft_m_time(path);
    stat(path, &buf);
    stat(path1, &buf1);
    return(buf.st_mtime < buf1.st_mtime);
}

void    suffle_time(char **paths)
{
    int     i;
    int     sort;
    char    *temp;

    sort = 0;
    while (!sort)
    {
        i = 0;
        while (paths[i + 1])
        {
            if (ft_st_time(paths[i], paths[i + 1]))
            {
                temp = paths[i];
                paths[i] = paths[i + 1];
                paths[i + 1] = temp;
            }
            i++;
        }
        i = 0;
        sort = 1;
       	while (paths[i + 1] && sort)
		{
			if (ft_st_time(paths[i], paths[i + 1]))
				sort = 0;
			i++;
		}
    }
}
/*
void	ft_tflag(int argc, char **argv, d_list *find_data)
{
	int i;

	i = 0;	
	if (argc == 2)
	{
		ft_otherdir(".", find_data);
///...		ft_tsort(find_data->dr, find_data);
	//	ft_store_time(find_data->dir_strings[1], find_data, 0);
	//	printf("argv: %s, find_data: %s\n", argv[0], find_data->mtime[0]);
		suffle_time(find_data->dr);
		while (find_data->dr[i] != NULL && argv)
		{
//			printf("%s\n", find_data->mtime[i]);
			// printf(">>%d\n", find_data->time[i]);
//			ft_putendl(ft_tsort(find_data->dir_strings, find_data));
			i++;
		}
		ft_strdel(find_data->mtime);
	}
}
*/