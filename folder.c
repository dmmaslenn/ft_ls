/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   folder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:18:41 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/05/16 17:05:40 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*add(char *d, char *d_name)
{
	char *c;

	c = (char *)malloc(sizeof(char) * (ft_strlen(d) + ft_strlen(d_name) + 2));
	ft_bzero(c, ft_strlen(c));
	strcat(c, d);
	strcat(c, "/");
	strcat(c, d_name);
	c[ft_strlen(c)] = '\0';
	return (c);
}

char	*folderdelete(t_dbl *list)
{
	int i;

	if (ft_strcmp(list->path, list->tail->d[0].path) == 0)
	{
		list->folder = list->path;
		return (list->path);
	}
	else
	{
		i = ft_strlen(list->folder);
		while (list->folder[i] != '/')
			i--;
		i--;
		list->folder = ft_strdup(ft_strsub(list->folder, 0, i + 1));
	}
	return (list->folder);
}

char	*folderprint(t_dbl *list, int i)
{
	ft_putstr("\n");
	if (ft_strcmp(list->path, add(list->tail->d[0].path,\
		list->tail->d[i].name)) == 0)
	{
		ft_putstr(list->path);
		ft_putstr(":\n");
		return (list->path);
	}
	else
	{
		list->folder = add(list->folder, list->tail->d[i].name);
		ft_putstr(list->folder);
		ft_putstr(":\n");
	}
	return (list->folder);
}

t_dbl	*help(t_dbl *list)
{
	list->tail = list->tail->prev;
	list->tail->next = NULL;
	return (list);
}

int		folder(t_dbl *list)
{
	int i;

	if (list->tail->d[0].id > 0)
		i = list->tail->d[0].id + 1;
	else
		i = 1;
	while (i < list->tail->d[0].i + 1)
	{
		if ((list->tail->d[i].f == 1) && (ft_strcmp(list->tail->d[i].name, ".")\
			!= 0) && (ft_strcmp(list->tail->d[i].name, "..") != 0) && list->tail->d[i].denied != 0)
		{
			list->tail->d[0].id = i;
			folderprint(list, i);
			letsdoit(add(list->tail->d[0].path, list->tail->d[i].name), list);
			if (list->tail->d[0].id > 0)
				i = list->tail->d[0].id + 1;
		}
		else if (list->tail->d[i].denied == 0)
		{
			ft_putchar('\n');
			ft_putstr("ls: ");
			ft_putstr(list->tail->d[i].name);
			ft_putstr(": Permission denied\n");
		} 
		i++;
	}
	if (list->tail == list->head)
		return (0);
	help(list);
	folderdelete(list);
	folder(list);
	return (0);
}
