/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 08:13:30 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/13 22:13:59 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	run(int c, d_list *find_data)
{
	ft_otherdir(".", find_data);
	while (find_data->dr[c] != NULL)
	{
		ft_putendl(find_data->dr[c]);
		ft_strdel(&find_data->dr[c]);
		c++;
	}
}

int	main(int argc, char **argv)
{
	int				i;
	int				c;
	t_dir			start[1024];
	struct s_flags	*m_flags;
	struct c_list	*find_data;

	m_flags = (t_flags *)malloc(sizeof(t_flags));
	find_data = (d_list *)malloc(sizeof(d_list));
	i = 1;
	if (argc < 2)
	{
		if (argv[0])
		{
			c = 0;
			run(c, find_data);
		}
		free(find_data);
	}
	else
	{
		do_flags(argc, argv, m_flags, find_data, start);
		free(m_flags);
	}
	sleep(10);
	return (0);
}
