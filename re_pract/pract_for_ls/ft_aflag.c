/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:20:55 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/20 12:37:46 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_aflag(int argc, char **argv, t_flags *m_flags, d_list *find_data)
{
	int	i;
	int	d;

	i = 1;
	while (i < argc && ft_check_flags(argc, argv) == 0)
	{
		i++;
	}
	i++;
	printf("%s\n", argv[i]);
	if (m_flags->a_flag == 1)
	{
		if (argc == 2)
		{
			i = 0;
			ft_a_currentdir(find_data);
			while (find_data->strings[i] != NULL)
				printf("%s\n", find_data->strings[i++]);
		}
		else
		{
			i = 1;
			while (i < argc && ft_check_flags(argc, argv) == 0)
			{
				i++;
			}
			i++;
			while (argv[i] != NULL)
			{
				d = 0;
				printf("WOWOWOWOW!!!\n");
				find_data->path = ft_strdup(ft_strjoin(argv[i], "/"));
				printf("%s\n", argv[i]);
				printf("%s\n", find_data->strings[d]);
				ft_a_otherdir(find_data->path/*argv[i]*/, find_data);
				while (find_data->strings[d] != NULL)
					printf("%s\n", find_data->strings[d++]);
				i++;
			}
		}
	}
}
