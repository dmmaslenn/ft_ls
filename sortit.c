/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:08:48 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/05/16 17:06:40 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*spinit(t_dbl *list, int argc, char **argv, char *c)
{
	while ((list->aa < argc - list->ii) && argv[list->aa + 1] && 		\
			(argv[list->aa + 1][list->bb] != '\0') && (c[list->bb] != '\0'))
	{
		if (c[list->bb] > argv[list->aa + 1][list->bb])
		{
			c = strdup(argv[list->aa + 1]);
			break ;
		}
		else if (c[list->bb] < argv[list->aa + 1][list->bb])
			break ;
		else
		{
			list->bb++;
			if (argv[list->aa + 1][list->bb] == '\0')
			{
				c = strdup(argv[list->aa + 1]);
				break ;
			}
			else if (c[list->bb] == '\0')
				break ;
		}
	}
	return (c);
}

char		*sorting(t_dbl *list, int argc, char **argv, char *c)
{
	while (list->aa < argc - list->ii - 1)
	{
		if (!argv[list->aa + 1])
			break ;
		c = spinit(list, argc, argv, c);
		list->bb = 0;
		list->aa++;
	}
	return (c);
}

char		*spinittwice(t_dbl *list, int argc, char **argv, char *c)
{
	while ((list->aa < argc - list->ii) && argv[list->aa + 1] && 	\
				(argv[list->aa + 1][list->bb] != '\0') && (c[list->bb] != '\0'))
	{
		if (c[list->bb] < argv[list->aa + 1][list->bb])
		{
			c = strdup(argv[list->aa + 1]);
			break ;
		}
		else if (c[list->bb] > argv[list->aa + 1][list->bb])
			break ;
		else
		{
			list->bb++;
			if (argv[list->aa + 1][list->bb] == '\0')
				break ;
			else if (c[list->bb] == '\0')
			{
				c = strdup(argv[list->aa + 1]);
				break ;
			}
		}
	}
	return (c);
}

char		*rsorting(t_dbl *list, int argc, char **argv, char *c)
{
	while (list->aa < argc - list->ii - 1)
	{
		if (!argv[list->aa + 1])
			break ;
		c = spinittwice(list, argc, argv, c);
		list->bb = 0;
		list->aa++;
	}
	return (c);
}

t_f			*decideit(t_dbl *list, t_f *q, char **c, int i)
{
	if (list->t == 1 && list->r == 1)
		q = revttimme(q, c);
	else if (list->t == 1)
		q = ttimme(q, c);
	else if (list->r == 1)
		q = rsort(c, i, q, list);
	else
		q = sort(c, i, q, list);
	return (q);
}
