/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:29:20 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/05/17 17:15:49 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dbl				*cll(void)
{
	t_dbl			*tmp;

	tmp = (t_dbl *)malloc(sizeof(t_dbl));
	tmp->size = 0;
	tmp->tail = NULL;
	tmp->head = tmp->tail;
	return (tmp);
}

int					addit(t_dbl *list, t_node *tmp)
{
	if (tmp == NULL)
		return (0);
	else if (list->tail == list->head)
	{
		list->tail = tmp;
		list->head->next = tmp;
		tmp->prev = list->head;
	}
	else
	{
		list->tail->next = tmp;
		tmp->prev = list->tail;
		list->tail = tmp;
		tmp->next = NULL;
	}
	list->size++;
	return (0);
}

void				dll(t_dbl *list)
{
	t_node			*tmp;
	t_node			*next;

	tmp = list->head;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(list);
}

t_dbl				*createlist(void)
{
	t_dbl			*list;

	list = cll();
	list->head = NULL;
	return (list);
}

char				**whileone(t_dbl *list, t_f *q)
{
	int				s;
	char			**c;
	int				i;
	DIR				*dir;
	struct dirent	*pdir;

	s = 0;
	i = 0;
	dir = opendir(q[0].path);
	if (dir == NULL)
		return (0);
	while ((pdir = readdir(dir)) != NULL)
	{
		if (list->a == 0 && pdir->d_name[0] == '.')
			s++;
		else
			i++;
	}
	c = (char **)malloc(sizeof(char *) * i);
	return (c);
}
