/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:02:12 by nlunga            #+#    #+#             */
/*   Updated: 2019/05/27 15:28:25 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int nb)
{
	if (nb >= 'a' && nb <= 'z')
	{
		nb = nb - 32;
		return (nb);
	}
	else
		return (nb);
}
