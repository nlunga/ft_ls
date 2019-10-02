/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:43:17 by nlunga            #+#    #+#             */
/*   Updated: 2019/10/02 14:49:06 by nlunga           ###   ########.fr       */
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
