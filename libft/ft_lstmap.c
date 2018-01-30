/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:49:14 by dmaslenn          #+#    #+#             */
/*   Updated: 2016/12/05 12:29:27 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *i;

	if (!lst)
		return (NULL);
	list = ft_lstnew(lst->content, lst->content_size);
	list = f(list);
	i = list;
	lst = lst->next;
	while (lst)
	{
		list->next = f(ft_lstnew(lst->content, lst->content_size));
		list = list->next;
		lst = lst->next;
	}
	list->next = NULL;
	return (i);
}
