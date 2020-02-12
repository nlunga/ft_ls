/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <nlunga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:43:17 by nlunga            #+#    #+#             */
/*   Updated: 2020/02/12 11:26:10 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

void	ft_bubblesort(t_dir order[])
{
	int		i;
	int		sort;
	char	*temp;

	sort = 0;
	while (!sort)
	{
		i = 0;
		while (order[i + 1].name)
		{
			if (ft_strcmp(order[i].name, order[i + 1].name) > 0)
			{
				temp = order[i].name;
				order[i].name = order[i + 1].name;
				order[i + 1].name = temp;
			}
			i++;
		}
		i = 0;
		sort = 1;
		while (order[i + 1].name && sort)
		{
			if (ft_strcmp(order[i].name, order[i + 1].name) > 0)
				sort = 0;
			i++;
		}
	}
}

void	numberSort(t_dir order[], int n) 
{
	int		i;
	int 	j;
	t_dir temp;
	
	i = 0;
	while (i < n-1)
	{
		j = 0;
		while (j  < n-i-1)
		{
			if (order[j].mtime > order[j+1].mtime)  {
            	printf("We should swap values: %d and %d\n", j, j + 1);
				temp = order[j];
				order[j] = order[j + 1];
				order[j + 1] = temp;

		
			//   ft_swap(&order[j].mtime, &order[j+1].mtime);
			}
			j++;
		}
		i++;
	}
} 

int		sort_time(char *file, char *file2)
{
	struct stat		buff;
	struct stat		buff2;

	stat(file, &buff);
	stat(file2, &buff2);
	return (buff.st_mtime < buff2.st_mtime);
}

void	ft_swap_str(char **str, char **str1)
{
	char	*temp;

	temp = *str;
	*str = *str1;
	*str1 = temp;
}

void	ft_store_time(char **path, char **path1, char *str)
{
	struct stat		buf;
	struct stat		buf1;
	//struct timespec st_mtim;
	char			*s1;
	char			*s2;

	s1 = ft_strjoin(str, *path);
	s2 = ft_strjoin(str, *path1);
	stat(s1, &buf);
	stat(s2, &buf1);
	if (buf.st_mtime < buf1.st_mtime)
		ft_swap_str(path, path1);
	else
	{
		if (buf.st_mtime == buf1.st_mtime)
		{
			if (buf.st_mtimespec.tv_nsec < buf1.st_mtimespec.tv_nsec)
		//	if (buf.st_mtim.tv_sec < buf1.st_mtim.tv_sec)
				ft_swap_str(path, path1);
		}
	}
}

char	**ft_tflag(char *dir, char **array, int n)
{
	int		i;
	int		k;
	char	*str;

	str = ft_strjoin(dir, "/");
	i = 0;
	while (i < n - 1)
	{
		k = 0;
		while (k < (n - i - 1))
		{
			ft_store_time(&array[k], &array[k + 1], str);
			k++;
		}
		i++;
	}
	free(str);
	return (array);
}

void	ft_get_time(t_dir time[])
{
	int			i;
	struct stat	buf;

	i = 0;
	while (time[i].name != NULL)
	{
		if (lstat(time[i].name, &buf) < 0){
			perror(time[i].name);
			return ;
		}
		time[i].mtime = buf.st_mtimespec.tv_nsec;
		i++;
	}
}

void	ft_timesort(t_dir da_time[])
{
	int		i;
	int		sort;
	char	*temp;

//	ft_get_time(da_time);
	sort = 0;
	while (!sort)
	{
		i = 0;
		while (da_time[i + 1].name)
		{
			if (da_time[i].mtime < da_time[i + 1].mtime)
			{
				temp = da_time[i].name;
				da_time[i].name = da_time[i + 1].name;
				da_time[i + 1].name = temp;
			}
			i++;
		}
		i = 0;
		sort = 1;
		while (da_time[i + 1].name && sort)
		{
			if (ft_strcmp(da_time[i].name, da_time[i + 1].name) > 0)
				sort = 0;
			i++;
		}
	}
	
}

void	ft_fixtime(t_dir sane[])
{
	int			i;
	int			sort;
	struct stat	buf;
	char		*temp;

	i = 0;
	while (sane[i].name != NULL)
	{
		lstat(sane[i].name, &buf);
		sane[i].mtime = buf.st_mtime;
		i++;
	}
//	i = 0;

//	ft_get_time(da_time);
	sort = 0;
	while (!sort)
	{
		i = 0;
		while (sane[i + 1].name)
		{
			if (sane[i].mtime < sane[i + 1].mtime)
			{
				temp = sane[i].name;
				sane[i].name = sane[i + 1].name;
				sane[i + 1].name = temp;
			}
			i++;
		}
		i = 0;
		sort = 1;
		while (sane[i + 1].name && sort)
		{
			//if (ft_strcmp(da_time[i].name, da_time[i + 1].name) > 0)
			if (sane[i].mtime < sane[i + 1].mtime)
				sort = 0;
			i++;
		}
	}

}
