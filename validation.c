/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:57:50 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/05/17 17:29:12 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		checkflag(char c, t_dbl *list)
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

int		checkl(int i, int c, char **argv, t_dbl *list)
{
	while (argv[i][c] != '\0')
	{
		if (argv[i][c] != 't' && argv[i][c] != 'l' && argv[i][c] != 'r' && \
			argv[i][c] != 'R' && argv[i][c] != 'a')
		{
			if (list->k != 1)
			{
				ft_putstr("illegal option -- ");
				ft_putchar(argv[i][c]);
				ft_putchar('\n');
				ft_putstr("usage: ls [-Ralrt] [file ...]");
				ft_putchar('\n');
			}
			list->k = 1;
			return (0);
		}
		else
			checkflag(argv[i][c], list);
		c++;
	}
	return (1);
}

int		checkll(int i, int c, char **argv, t_dbl *list)
{
	while (argv[i][c] != '\0')
	{
		if (argv[i][c] != 't' && argv[i][c] != 'l' && argv[i][c] != 'r' && \
			argv[i][c] != 'R' && argv[i][c] != 'a')
			return (0);
		else
			checkflag(argv[i][c], list);
		c++;
	}
	return (1);
}

int		checkthis(t_dbl *list, char **argv, int w, int k)
{
		if (argv[list->mm][list->ff] == '-' && list->ff == 0 && list->mm == k)
		{
			k += 1;
			if (argv[list->mm][list->ff + 1] == '\0')
				return (w);
			if (checkll(list->mm, list->ff + 1, argv, list) == 0)
				return (-1);
			if (!argv[list->mm + 1])
				return (w);
		}
		else if ((argv[list->mm][list->ff] == '-' && list->ff == 0 && \
				list->mm != k) || (checkfolder(list, argv, list->mm) == 0))
		{
			if (!argv[list->mm + 1])
				return (w);
		}
		else if (checkfolder(list, argv, list->mm) == 1)
			w++;
	return (w);
}

int		checkthisbuf(int argc, char **argv, t_dbl *list)
{
	int k;
	int w;
	
	list->mm = 1;
	k = 1;
	w = 0;
	while (list->mm <  argc)
	{
		list->ff = 0;
		if (checkthis(list, argv, w, k) == -1)
			return (0);
		list->ff = 0;
		w = checkthis(list, argv, w, k);
		list->mm++;
	}
	return (w);
}
