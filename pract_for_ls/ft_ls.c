/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 08:13:30 by nlunga            #+#    #+#             */
/*   Updated: 2019/07/12 15:22:54 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_libft/ft_libft.h"

/*
char	*ft_ls(char *command, char *options, ...)
{
	char	*str;
	str = ft_strnew(ft_strlen(command));
	str = command;
	if (str != "ft_ls")
	{
		ft_putendl("ERROR! : incorrect command");
	}
}*/

int	checkflags(char **argv)
{
	if (argc == 2)
		if (argv[1] == "-l")
}

void	ft_currentdir(int argc, char **argv)
{
	DIR				*dir;
	struct dirent	*sd;

	if (argc == 1)
	{
		if (argv[0])
		{
			dir = opendir(".");
			if (dir == NULL)
			{
				ft_putendl("ERROR! unable to open directory");
			}
			while ((sd = readdir(dir)) != NULL)
			{
				//ft_putstr("");
				ft_putendl(sd->d_name);
			}
			
			closedir(dir);
		}
	}
}
/*
void	ft_opendir(char **argv)
{
	DIR				*dir;
	struct dirent 	*sd;
	
	dir = opendir(*argv[i]);
	if (dir == NULL)
	{
		ft_putendl("ERROR! unable to open directory");
		exit(1);
	}
	while((sd = readdir(dir)) != NULL)
	{
		ft_putstr("->> ");
		ft_putendl(sd->d_name);
	}

	closedir(dir);
}

int		ft_ls(int argc, char **argv)
{
	if (argc == 1)
	{
		int i;

		i = 0;
		while (*argv[i])
		{
			ft_opendir(*argv[i]);
			i++;
		}

	}
	return (0);
}
*/
int	main(int argc, char **argv)
{
	if (argc == 1)
		if (argv[0])
			ft_currentdir(argc, argv);
	return (0);
}

// when someone runs the ft_ls program
// the program must take in a certain number of parameters
// the first parameter is the program name
// if you just ran the program without adding any parameter
// the program must print the items within the current directory
// if you ran the program with parameters
// check which parameters are options
// you can identify an option because it has '-' infront of the option
// if not an option is it a directory
// if it's directory open it and print out its contents
// 
// a way to handle indefine arity is through the use of linked lists
// strsplit the arguments removing all the spacing
// use 
// create a list and then iterate trough the lists
// store the last variable/node of the list somewhere
//
