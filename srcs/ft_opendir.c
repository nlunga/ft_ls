/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <nlunga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 09:29:08 by nlunga            #+#    #+#             */
/*   Updated: 2020/02/12 11:56:16 by nlunga           ###   ########.fr       */
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

//Time_t test

static void printTime(time_t now) {
	// time_t     now;
    struct tm *ts;
    char       buf[80];

    /* Get the current time */
    // now = time(NULL);

    /* Format and print the time, "ddd yyyy-mm-dd hh:mm:ss zzz" */
    ts = localtime(&now);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", ts);
    puts(buf);

    return ;
}


//End of time_t test



// void	ft_opendirtime(char *path, t_dir data[], t_dir time[])
void	ft_opendirtime(char *path, t_dir data[])
{
	DIR				*dir;
	struct dirent	*sd;
	struct stat		buf;
	int				i;

	i = 0;
	dir = opendir(path);
	if (dir == NULL)
		ft_putendl("Error!!!");
	printf("This is before time sort:\n");
	while ((sd = readdir(dir)) != NULL)
	{
		// if (*sd->d_name != '.')
		// {
			data[i].name = ft_strdup(sd->d_name);
			if (lstat(data[i].name, &buf) < 0){
				perror(data[i].name);
				return ;
			}
			// data[i].mtime = buf.st_mtimespec.tv_nsec;
			// data[i].file = buf;
			data[i].mtime = buf.st_mtime;
			printf("%s\n", data[i].name);
			printf("%d\n", data[i].mtime);

			//Print time
			ft_putstr("Value of time: ");
			printTime(data[i].mtime);
			ft_putendl("");
		// }
		i++;
	}
	// ft_get_time(data);
	numberSort(data, ft_structlen(data));
	printf("\nThis is after data sort:\n");	
	i = 0;
	printf("test\n\n");
	while(data[i].name != NULL)
	{
		// printf(" that");
		// printf("%s\n", data[i].name);
		// if (*data[i].name == '.' || ft_strcmp(data[i].name, "..") == 0)
			// i++;
		printf("this is: %s\n", data[i].name);
		// printf("this is data %d : %d\n", i, data[i].mtime);
		i++;
	}
	// i = 0;
	// while (data[i].name)
	// {
	// 	if (lstat(data[i].name, &buf) < 0){
	// 			perror(data[i].name);
	// 			return ;
	// 	}
	// 	if (buf.st_mtimespec.tv_nsec == data[i].mtime)
	// 		printf("this is time %d belong to %s: %d\n", i, data[i].name, data[i].mtime);
	// 	i++;
	// }
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