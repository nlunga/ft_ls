/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 09:23:53 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/30 13:06:50 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

/*void	ft_display(t_dir print[])
{
	int		i;

	i = 0;
	while (print[i].name != NULL )
	{
		ft_putendl(print[i].name);
		ft_strdel(&print[i].name);
		i++;
	}
}*/

int	main(int ac, char **av)
{
	int		i;
	t_dir	*start;
	t_flags	*mflag;

	if (!(start = (t_dir *)malloc(sizeof(t_dir *))))
		return (0);
	if (!(mflag = (t_flags *)malloc(sizeof(t_flags))))
		return (0);
	i = 0;
	if (ac == 1 && av)
	{
		ft_opendir(".", start);
		while (start[i]->name != NULL)
		{
			ft_putendl(start[i]->name);
			ft_strdel(&start[i]->name);
			i++;
		}
	}
	else
	{
		ft_lflag(av, mflag, start);
	}
	free(start);
	free(mflag);
	sleep(10);
	return (0);
}
