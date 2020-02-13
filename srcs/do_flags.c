/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 08:47:48 by nlunga            #+#    #+#             */
/*   Updated: 2020/02/13 08:47:53 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

void	do_flags(int argc, char **argv, t_flags *m_flag, t_dir *find_data)
{
	int i;
	// int c;

	i = 1;
    ft_verflag(argv, m_flag);
    if (ft_check_flags(argv))
    {
        if (m_flag->l_flag == 1)
            // printf("This is wrong\n");
            ft_lflag(argv, m_flag, find_data);
        if (m_flag->a_flag == 1)
            ft_aflag(argc, argv, m_flag,find_data);
        if (m_flag->t_flag == 1)
            ft_timeflag(argv, m_flag, find_data);
            // ft_aflag(argc, argv, m_flag, find_data);
        /*if (m_flag->r_flag == 1)
            ft_rflag(argc, argv, m_flag, find_data);
        if (m_flag->cr_flag == 1)
            ft_crflag(argc, argv, m_flag, find_data);*/
            // ft_tflag(".", find_data->dr, ft_arrlen(find_data->dr));
        /*if (!ft_check_flags(argc, argv))//else
        {
            c = 0;
            while (argv[i] != NULL)
            {
                ft_putstr(argv[i]);
                ft_putendl(":");
                ft_otherdir(argv[i], find_data);
                while (find_data->dr[c] != NULL)
                {
                    ft_putendl(find_data->dr[c]);
                    ft_strdel(&find_data->dr[c]);
                    c++;
                }
                ft_putendl(" ");
                i++;
            }
        }*/
    }
}