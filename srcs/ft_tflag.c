/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <nlunga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:42:20 by nlunga            #+#    #+#             */
/*   Updated: 2020/02/12 09:58:44 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

void    ft_timeflag(char **path, t_flags *mflag, t_dir *data)
{
    int			i;
	// int			j;
	// struct stat	buf;

	i = 0;
    ///////////////////////////////
    // int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    // int n = sizeof(arr)/sizeof(arr[0]);
    ///////////////////////////////
	while (ft_check_flags(&path[i]))
		i++;
	i++;
	ft_verflag(path, mflag);    
    if (mflag->t_flag == 1)
    {
        if (i == 2 && path[i] == NULL)
		{
            ft_opendirtime(".", data);
            // printf("this is the first time%d\n", data->mtime);
            // ft_displaytime(data, ft_structlen(data));
            // numberSort(&data->mtime, ft_structlen(data)); //
		    // printf("Sorted array: \n"); //
		    // printArray(&data->mtime, ft_structlen(data)); //
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