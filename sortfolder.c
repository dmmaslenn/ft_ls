/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfolder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:08:30 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/05/30 16:08:32 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				**sortr(char **d, t_dbl *list)
{
	char			**c;
	char 			*f;
	int i;
	int a;

	i = 0;
	a = 0;
	c = (char **)malloc(sizeof(char *) * list->erf);
	while (i < list->erf)
	{
		f = ft_strdup(d[a]);
		f = sortingr(list, a, d, f, i);
		c[i] = ft_strdup(f);
		i++;
		a = 0;
		d = excluder(list, d, f, i);
		if (i == list->erf - 1)
		{
			c[i] = ft_strdup(d[0]);
			break ;
		}
	}
	return (c);
}

char		*sortingr(t_dbl *list, int a, char **d, char *f, int i)
{
	int b;

	b = 0;
	while (a < list->erf - i - 1)
	{
		if (!d[a + 1])
			break ;
		f = spinitr(list, a, d, f, i, b);
		b = 0;
		a++;
	}
	return (f);
}

char		*spinitr(t_dbl *list, int a, char **d, char *f, int i, int b)
{
	while ((a < list->erf - i) && d[a + 1] && 		\
			(d[a + 1][b] != '\0') && (f[b] != '\0'))
	{
		if (f[b] > d[a + 1][b])
		{
			f = strdup(d[a + 1]);
			break ;
		}
		else if (f[b] < d[a + 1][b])
			break ;
		else
		{
			b++;
			if (d[a + 1][b] == '\0')
			{
				f = strdup(d[a + 1]);
				break ;
			}
			else if (f[b] == '\0')
				break ;
		}
	}
	return (f);
}

char				**excluder(t_dbl *list, char **d, char *c, int q)
{
	char			**f;
	int				i;
	int				k;
	int				a;

	i = 0;
	k = 0;
	a = 0;
	while (ft_strcmp(d[i], c) != 0)
		i++;
	f = (char **)malloc(sizeof(char *) * list->erf - q);
	while (k < i)
	{
		f[a] = ft_strdup(d[k]);
		a++;
		k++;
	}
	k++;
	while (a < list->erf - q)
	{
		f[a] = ft_strdup(d[k]);
		a++;
		k++;
	}
	return (f);
}