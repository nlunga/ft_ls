/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 09:23:53 by nlunga            #+#    #+#             */
/*   Updated: 2019/10/03 16:16:53 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

int	main(int ac, char **av)
{
	int		size = 1024;
	t_dir	start[size];
	t_flags	*mflag;

	if (!(mflag = (t_flags *)malloc(sizeof(t_flags))))
		return (0);
	if (ac == 1 && av)
	{
		ft_opendir(".", start);
		ft_fixtime(start);
		ft_display(start, ft_structlen(start));
	}
	else
	{
	//	ft_lflag(av, mflag, start);
	}
	free(mflag);
//	sleep(10);
	return (0);
}
