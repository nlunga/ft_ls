/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:16:39 by nlunga            #+#    #+#             */
/*   Updated: 2019/08/27 09:05:36 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*char	**ft_sort(int argc,void	 (*ft_currentdir)(d_list), d_list *find_data)
{
	int i;
	int j;
	int k;

	j = 0;
	i = 1;
	if (argc == 1)
	{
		//ft_currentdir(find_data);
		j = 0;
		while (find_data->strings[j] != NULL)
			j++;
		char	*key;
		i = 1;
		while (i < j)
		{
			key = ft_strdup(find_data->strings[i]);
			k = i-1;
			while (k >= 0 && find_data->strings[k] > key)
			{
				find_data->strings[k + 1] = find_data->strings[k];
				k = k - 1;
			}
			find_data->strings[k + 1] = key;
			i++;
		}
		return(find_data->strings);
	}
	return (NULL);
}
*/
/*
void	string_sort(char **arr,const int len,int (*cmp_func)(const char *a, const char *b))
{

}
*/
/*
void	**ft_sort(char **temp,void (*ft_currentdir)(d_list), d_list *find_data)
{
	int i;
	int j;
	int k;

	j = 0;
	i = 1;
	if (argc == 1)
	{
		//ft_currentdir(find_data);
		j = 0;
		while (find_data->strings[j] != NULL)
			j++;
		char	*key;
		i = 1;
		while (i < j)
		{
			key = ft_strdup(find_data->strings[i]);
			k = i-1;
			while (k >= 0 && find_data->strings[k] > key)
			{
				find_data->strings[k + 1] = find_data->strings[k];
				k = k - 1;
			}
			find_data->strings[k + 1] = key;
			i++;
		}
		return(find_data->strings);
	}
	return (NULL);
}
*/

int	main(int ac, char **av)
{
	d_list *find_data;
	find_data = (d_list *)malloc(sizeof(d_list));
	
	if (ac == 1)
	{
		int i;

		i = 0;
		ft_currentdir(find_data);
		while (find_data->strings[i] != NULL)
			ft_putendl(find_data->strings[i++]);
	}
	return (0);
}
