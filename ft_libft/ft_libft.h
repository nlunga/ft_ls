/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:46:26 by nlunga            #+#    #+#             */
/*   Updated: 2019/07/16 09:30:49 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <dirent.h>
# include <sys/types.h>
# include <time.h>
# include <stdio.h>
typedef char** str_Arr;

typedef	struct	num_arg
{
	char				*options;
	struct	num_arg 	*next;
}						num_arg_t;

#endif
