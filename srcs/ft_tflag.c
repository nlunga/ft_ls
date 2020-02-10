/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <nlunga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:42:20 by nlunga            #+#    #+#             */
/*   Updated: 2020/02/10 15:22:46 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

void    ft_timeflag(char **path, t_flags *mflag, t_dir *data)
{
    int			i;
	// int			j;
	// struct stat	buf;

	i = 0;
	while (ft_check_flags(&path[i]))
		i++;
	i++;
	ft_verflag(path, mflag);    
    if (mflag->t_flag == 1)
    {
        if (i == 2 && path[i] == NULL)
		{
            ft_opendirtime(".", data);
            printf("hi");
            // ft_displaytime(data, ft_structlen(data));
        }else
        {
            while (path[i] != NULL)
			{
                ft_opendir(path[i], data);
                i++;
            }
        }
        
    }
}
// if the -t flag exists check to see if there are two args or more
// if there are two args sort current dir by time
// if there are more than two args open dir then dir then sort by time