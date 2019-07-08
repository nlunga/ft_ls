/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:29:23 by nlunga            #+#    #+#             */
/*   Updated: 2019/07/08 11:33:52 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"
#include "ft_libft/ft_libft.h"

int main(int argc, char **argv)
{
	DIR				*dir;
	struct direct	*sd;

	dir = opendir("ft_libft");
	if (dir == NULL)
	{
		printf("Error! unable to open directory");
	}

	sd = readdir(dir);
	while (sd != NULL)
	{
		printf(">> %s\n", *(sd->d_name));
	}
	closedir(dir);

	return (0);
}
