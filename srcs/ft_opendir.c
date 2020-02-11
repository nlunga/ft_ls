/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <nlunga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 09:29:08 by nlunga            #+#    #+#             */
/*   Updated: 2020/02/11 15:27:56 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

void	ft_opendir(char *path, t_dir data[])
{
	DIR				*dir;
	struct dirent	*sd;
	int				i;

	i = 0;
	dir = opendir(path);
	if (dir == NULL)
		ft_putendl("Error!!!");
	while ((sd = readdir(dir)) != NULL)
	{
		data[i].name = ft_strdup(sd->d_name);
		i++;
	}
//	ft_bubblesort(&data->name);
	//ft_bubblesort(data);
	closedir(dir);
}

void	ft_opendirtime(char *path, t_dir data[])
{
	DIR				*dir;
	struct dirent	*sd;
	int				i;

	i = 0;
	dir = opendir(path);
	if (dir == NULL)
		ft_putendl("Error!!!");
	printf("This is before time sort:\n");
	while ((sd = readdir(dir)) != NULL)
	{
		if (*sd->d_name != '.')
		{
			data[i].name = ft_strdup(sd->d_name);
			printf("%s\n", data[i].name);
		}
		i++;
	}
	ft_get_time(data);
	numberSort(data, ft_structlen(data));
	// printf("the first %d\n", data[0].mtime);
	// printf("the second %d\n", data[1].mtime);
	// printf("the third %d\n", data[2].mtime);
	// printf("the fouth %d\n", data[3].mtime);
	// printf("\nThis is after time sort:\n");	
	i = 0;
	printf("test\n\n");
	while(data[i].mtime)
	{
		// printf(" that");
		// printf("%s\n", data[i].name);
		printf("%s\n", data[i].name);
		i++;
	}
	closedir(dir);
}


void	ft_opendirsorted(char *path, t_dir data[])
{
	DIR				*dir;
	struct dirent	*sd;
	int				i;

	i = 0;
	dir = opendir(path);
	if (dir == NULL)
		ft_putendl("Error!!!");
	while ((sd = readdir(dir)) != NULL)
	{
		if (*sd->d_name != '.')
		{
			data[i].name = ft_strdup(sd->d_name);
			i++;
		}
	}
	ft_bubblesort(data);
	closedir(dir);
}