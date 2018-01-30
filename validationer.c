/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validationer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:47:01 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/05/30 14:47:02 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			validationr(int argc, char **argv, t_dbl *list)
{
	int		i;
	int		c;

	i = 1;
	c = 0;
	list->u = 0;
	list->ww = 0;
	list->w = checkthisbufr(argc, argv, list); 
	while (i < argc)
	{
		list->u = 0;
		if (whilejr(list, argv, i, c) == 0)
			return (0);
		else
		{
			list->err = 0;
			i = whilejr(list, argv, i, c);
		}
		i++;
	}
	return (list->ww);
}

int			errorr(char **argv, int i, t_dbl *list)
{
	list->error = 1;
	if (list->ert == 0)
		list->erf++;
	else
	{
		list->c[list->erf] = ft_strdup(argv[i]);
		list->erf++;
	}
	return (0);
}

int			checkfolderr(t_dbl *list, char **argv, int i)
{
	DIR		*dir;

	if (argv[i][0] == '/')
		dir = opendir(argv[i]);
	else
		dir = opendir(add(list->path, argv[i]));
	if (dir == NULL)
		return (0);
	return (1);
}

int		er(char **argv, int c, t_dbl *list, int i)
{
	if (argv[i][c + 1] == '\0')
		return (0);
	if (checklr(i, c + 1, argv, list) == 0)
		return (0);
	if (!argv[i + 1])
		return (0);
	return (1);
}

int		whilejr(t_dbl *list, char **argv, int i, int c)
{
	int k;

	k = 1;
	while (argv[i][c] != '\0')
	{
		if (argv[i][c] == '-' && c == 0 && i == k)
		{
			k += 1;
			if (e(argv, c, list, i) == 0)
				return (0);
			i++;
			c = -1;
		}
		else if ((argv[i][c] == '-' && c == 0 && i != k) ||\
			(checkfolderr(list, argv, i) == 0))
		{
			if (list->err == 0)
				errorr(argv, i, list);
			if (!argv[i + 1])
				return (0);
			i++;
			c = -1;
		}
		c++;
	}
	return (i);
}

int		heeelpr(t_dbl *list, int w)
{
	list->ff++;
	w++;
	return (w);
}

int		checkflagr(char c, t_dbl *list)
{
	if (c == 'a')
		list->a = 1;
	else if (c == 'R')
		list->rbf = 1;
	else if (c == 'r')
		list->r = 1;
	else if (c == 'l')
		list->l = 1;
	else if (c == 't')
		list->t = 1;
	return (0);
}

int		checklr(int i, int c, char **argv, t_dbl *list)
{
	while (argv[i][c] != '\0')
	{
		if (argv[i][c] != 't' && argv[i][c] != 'l' && argv[i][c] != 'r' && \
			argv[i][c] != 'R' && argv[i][c] != 'a')
		{
			list->k = 1;
			return (0);
		}
		else
			checkflagr(argv[i][c], list);
		c++;
	}
	return (1);
}

int		checkllr(int i, int c, char **argv, t_dbl *list)
{
	while (argv[i][c] != '\0')
	{
		if (argv[i][c] != 't' && argv[i][c] != 'l' && argv[i][c] != 'r' && \
			argv[i][c] != 'R' && argv[i][c] != 'a')
			return (0);
		else
			checkflagr(argv[i][c], list);
		c++;
	}
	return (1);
}

int		checkthisr(t_dbl *list, char **argv, int w, int k)
{
		if (argv[list->mm][list->ff] == '-' && list->ff == 0 && list->mm == k)
		{
			k += 1;
			if (argv[list->mm][list->ff + 1] == '\0')
				return (w);
			if (checkllr(list->mm, list->ff + 1, argv, list) == 0)
				return (-1);
			if (!argv[list->mm + 1])
				return (w);
		}
		else if ((argv[list->mm][list->ff] == '-' && list->ff == 0 && \
				list->mm != k) || (checkfolderr(list, argv, list->mm) == 0))
		{
			if (!argv[list->mm + 1])
				return (w);
		}
		else if (checkfolderr(list, argv, list->mm) == 1)
			w++;
	return (w);
}

int		checkthisbufr(int argc, char **argv, t_dbl *list)
{
	int k;
	int w;
	
	list->mm = 1;
	k = 1;
	w = 0;
	while (list->mm <  argc)
	{
		list->ff = 0;
		if (checkthisr(list, argv, w, k) == -1)
			return (0);
		list->ff = 0;
		w = checkthisr(list, argv, w, k);
		list->mm++;
	}
	return (w);
}
