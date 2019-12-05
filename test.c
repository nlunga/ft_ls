/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:29:23 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/13 22:54:40 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_libft/ft_libft.h"

int	main(int argc, char **argv)
{
	DIR				*dir;
	struct dirent	*sd;

	dir = opendir(".");
	if (dir == NULL)
	{
		printf("Error! unable to open directory \n");
		exit(1);
	}
	while ((sd = readdir(dir)) != NULL)
	{
		printf(">> %s\n", sd->d_name);
	}
	closedir(dir);
	return (0);
}
