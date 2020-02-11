/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <nlunga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 09:23:53 by nlunga            #+#    #+#             */
/*   Updated: 2020/02/11 09:55:18 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_ls.h"

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
}

int	main(int ac, char **av)
{
	int		size = 1024;
	t_dir	start[size];
	t_flags	*mflag;

	if (!(mflag = (t_flags *)malloc(sizeof(t_flags))))
		return (0);
	if (ac == 1 && av)
	{
		// numberSort(arr, n); 
		// printf("Sorted array: \n"); 
		// printArray(arr, n);
		ft_opendir(".", start);
		// ft_fixtime(start);
		ft_display(start, ft_structlen(start));
	}
	else
	{
		ft_lflag(av, mflag, start);
		ft_timeflag(av, mflag, start);
		// ft_display(start, ft_structlen(start));
	}
	free(mflag);
	// sleep(10);
	return (0);
}

/*
int ft_ls(char *name)
{
	//get
	//print and stuff
	if (-R)
	{
		foreach file in name_folder
			ft_ls(file);
			
	}
}

void	ft_ls(char *name, t_flag *flag)
{
	//use dir functions to get info
		//if not -a and ., don't add to array
	//get stat for each of them, store in array
	//sort
	//reverse
	//print (l or not)
	if (-l)
		print_long();
	else
		print_short();
	if (-R)
	{
		for(int i=0; i < len_arr; i++)
		{
			if (!. && !.. )
				ft_ls(name + / + arr[i].name, flag);
		}
	}
}

*/