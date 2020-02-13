/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <nlunga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:42:20 by nlunga            #+#    #+#             */
/*   Updated: 2020/02/12 10:50:13 by nlunga           ###   ########.fr       */
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
            ft_displaytime(data, ft_structlen(data));
        }else
        {
            if (ft_isdir(path[i]))
			{
                while (path[i] != NULL)
                {
                    ft_opendirtime(path[i], data);
                    // ft_displaytime(data, ft_structlen(data));
                    printf("Path is: %s", path[i]);
                    i++;
                }
            }else
            {
                ft_putendl(path[i]);
            }
        }
        
    }
}
// if the -t flag exists check to see if there are two args or more
// if there are two args sort current dir by time
// if there are more than two args open dir then dir then sort by time