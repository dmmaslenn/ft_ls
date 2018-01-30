/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 18:07:45 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/05/16 17:06:29 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_f					*readd(t_f *q, t_dbl *list)
{
	DIR				*dir;
	struct dirent	*pdir;
	int				i;
	int				s;
	char			**c;

	i = 0;
	s = 0;
	c = whileone(list, q);
	//ft_putstr(c[0]);
	dir = opendir(q[0].path);
	if (dir == NULL)
		return (0);
	while ((pdir = readdir(dir)) != NULL)
	{
		if (list->a == 0 && pdir->d_name[0] == '.')
			s++;
		else
		{
			c[i] = ft_strdup(pdir->d_name);
			i++;
		}
	}
	q = decideit(list, q, c, i);
	//ft_putchar('f');
	//ft_putnbr(q[0].i);
	return (q);
}

char				**exclude(char **d, char *c, int argc, int q)
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
	f = (char **)malloc(sizeof(char *) * argc - q);
	while (k < i)
	{
		f[a] = ft_strdup(d[k]);
		a++;
		k++;
	}
	k++;
	while (a < argc - q)
	{
		f[a] = ft_strdup(d[k]);
		a++;
		k++;
	}
	return (f);
}

t_f					*rsort(char **argv, int argc, t_f *q, t_dbl *list)
{
	char			*c;

	while (list->ii < argc)
	{
		if (!argv[1])
		{
			q[list->ii + 1].name = ft_strdup(argv[0]);
			break ;
		}
		c = strdup(argv[list->aa]);
		c = rsorting(list, argc, argv, c);
		q[list->ii + 1].name = ft_strdup(c);
		checkprivilege(q, list->ii + 1);
		list->ii++;
		list->aa = 0;
		argv = exclude(argv, c, argc, list->ii);
		if (list->ii == argc - 1)
		{
			q[list->ii + 1].name = ft_strdup(argv[0]);
			checkprivilege(q, list->ii + 1);
			break ;
		}
	}
	return (q);
}

t_f					*sort(char **argv, int argc, t_f *q, t_dbl *list)
{
	char			*c;

	while (list->ii < argc)
	{
		if (!argv[1])
		{
			q[list->ii + 1].name = ft_strdup(argv[0]);
			break ;
		}
		c = strdup(argv[list->aa]);
		c = sorting(list, argc, argv, c);
		q[list->ii + 1].name = ft_strdup(c);
		checkprivilege(q, list->ii + 1);
		list->ii++;
		list->aa = 0;
		argv = exclude(argv, c, argc, list->ii);
		if (list->ii == argc - 1)
		{
			q[list->ii + 1].name = ft_strdup(argv[0]);
			checkprivilege(q, list->ii + 1);
			break ;
		}
	}
	return (q);
}

t_f					*checkprivilege(t_f *q, int i)
{
	struct stat		filestat;

	lstat(add(q[0].path, q[i].name), &filestat);
	if (S_ISDIR(filestat.st_mode) == 1 && checkifdenied(add(q[0].path, q[i].name)) == 1)
		q[i].f = 1;
	else
		q[i].f = 0;
	return (q);
}
