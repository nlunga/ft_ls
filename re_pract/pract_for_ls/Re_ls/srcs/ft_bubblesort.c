/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:43:17 by nlunga            #+#    #+#             */
/*   Updated: 2019/10/01 16:57:46 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"
/*
void	ft_bubblesort(char **str)
{
	int		i;
	int		sort;
	char	*temp;

	sort = 0;
	while (!sort)
	{
		i = 0;
		while (str[i + 1])
		{
			if (ft_strcmp(str[i], str[i + 1]) > 0)
			{
				temp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = temp;
			}
			i++;
		}
		i = 0;
		sort = 1;
		while (str[i + 1] && sort)
		{
			if (ft_strcmp(str[i], str[i + 1]) > 0)
				sort = 0;
			i++;
		}
	}
}
*/
void	ft_bubblesort(t_dir order[])
{
	int		i;
	int		sort;
	char	*temp;

	sort = 0;
	while (!sort)
	{
		i = 0;
		while (order->name[i + 1])
		{
			if (ft_strcmp(order->name[i], order->name[i + 1]) > 0)
			{
				temp = order->name[i];
				order->name[i] = order->name[i + 1];
				order->name[i + 1] = temp;
			}
			i++;
		}
		i = 0;
		sort = 1;
		while (order->name[i + 1] && sort)
		{
			if (ft_strcmp(order->name[i], order->name[i + 1]) > 0)
				sort = 0;
			i++;
		}
	}
}
