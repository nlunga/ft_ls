/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 09:01:50 by nlunga            #+#    #+#             */
/*   Updated: 2019/09/30 09:08:25 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addpath(char *old_path, char *new_path)
{
	char	*path;
	
	if(ft_strcmp(old_path, new_path) == 0)
		return (new_path);
	path = ft_strjoin(ft_strjoin(old_path, "/"), new_path);
	return (path);
}
