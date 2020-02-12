/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:33:29 by nlunga            #+#    #+#             */
/*   Updated: 2019/06/21 10:11:51 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*start;

	if (lst == NULL || f == NULL)
		return (NULL);
	fresh = f(lst);
	start = fresh;
	while (lst->next != NULL)
	{
		fresh->next = f(lst->next);
		fresh = fresh->next;
		lst = lst->next;
	}
	return (start);
}
