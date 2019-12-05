/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: innocent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:07:50 by innocent          #+#    #+#             */
/*   Updated: 2019/09/16 10:07:52 by innocent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int    ft_st_time(char *path, char *path1)
{
    struct stat buf;
    struct stat buf1;
    //ft_m_time(path);
    stat(path, &buf);
    stat(path, &buf1);
    return(buf.st_mtimensec < buf1.st_mtimensec);
}

void    suffle_time(char **paths)
{
    int     i;
    int     sort;
    char    *temp;

    sort = 0;
    while (!sort)
    {
        i = 0;
        while (paths[i + 1])
        {
            if (ft_st_time(paths[i], paths[i + 1]))
            {
                temp = paths[i];
                paths[i] = paths[i + 1];
                paths[i + 1] = temp;
            }
            i++;
        }
        i = 0;
        sort = 1;
       	while (paths[i + 1] && sort)
		{
			if (ft_st_time(paths[i], paths[i + 1]))
				sort = 0;
			i++;
		}
    }
}

int main(void)
{
    char str[50] = "./libft";
    ft_st_time(str);
    return (0);
}

