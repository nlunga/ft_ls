/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <nlunga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:07:36 by nlunga            #+#    #+#             */
/*   Updated: 2020/02/10 15:12:00 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

void	ft_display(t_dir test[], int n)
{
	int		i;

	i = 0;
	ft_bubblesort(test);
//	ft_timesort(test);
//	ft_ttt(test);
	while (i < n)
	{
		if (*test[i].name != '.')
		{
			ft_putendl(test[i].name);
			ft_strdel(&test[i].name);
		}
		i++;
	}
}

void	ft_displayall(t_dir test[], int n)
{
	int		i;

	i = 0;
	ft_bubblesort(test);
	while (i < n)
	{
		ft_putendl(test[i].name);
		ft_strdel(&test[i].name);
		i++;
	}
}

void	ft_displayrev(t_dir test[], int n)
{
	n--;
	ft_bubblesort(test);
	while (n >= 0)
	{
		ft_putendl(test[n].name);
		ft_strdel(&test[n].name);
		n--;
	}
}

void	ft_displaytime(t_dir test[], int n)
{
	int		i;

	i = 0;
	// ft_bubblesort(test);
	ft_timesort(test);
//	ft_timesort(test);
//	ft_ttt(test);
	while (i < n)
	{
		if (*test[i].name != '.')
		{
			ft_putendl(test[i].name);
			ft_strdel(&test[i].name);
		}
		i++;
	}
}