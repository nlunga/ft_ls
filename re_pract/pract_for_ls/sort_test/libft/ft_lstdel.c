/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:50:11 by nlunga            #+#    #+#             */
/*   Updated: 2019/06/18 08:47:38 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*ptrnxt;

	ptr = *alst;
	while (ptr->next != NULL)
	{
		ptrnxt = ptr->next;
		del(ptr, ptr->content_size);
		ptr = ptrnxt;
	}
	del(ptr, ptr->content_size);
	*alst = NULL;
}
