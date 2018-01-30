/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:19:50 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/05/16 17:05:29 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			validation(int argc, char **argv, t_dbl *list)
{
	int		i;
	int		c;

	i = 1;
	c = 0;
	list->u = 0;
	list->ww = 0;
	list->w = checkthisbuf(argc, argv, list);
	if (checkthisbuf(argc, argv, list) > 0)
		list->q = (char **)malloc(sizeof(char *) * list->w);
	while (i < argc)
	{
		list->u = 0;
		if (whilej(list, argv, i, c) == 0)
			return (0);
		else
			i = whilej(list, argv, i, c);
		list->q[list->ww] = ft_strdup(argv[i]);
		list->ww++;
		i++;
	}
	return (list->ww);
}

int			error(char **argv, int i, t_dbl *list)
{
	list->error = 1;
	return (0);
}

int			checkfolder(t_dbl *list, char **argv, int i)
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

long getFileCreationTime(char *path) {
    struct stat attr;

    stat(path, &attr);
    return (attr.st_mtimespec.tv_nsec);
}

char *sortcheckr(char **ff, t_f *q, int f)
{
	int i;
	char *a;
	struct stat attr;
	long ttime;
	long time;

	i = 1;
	ttime = getFileCreationTime(add(q[0].path, ff[0]));
	a = ft_strdup(ff[0]);
		while (i < f)
		{
			time = getFileCreationTime(add(q[0].path, ff[i]));
			if (ttime > time)
			{
			ttime = time;
			a = ft_strdup(ff[i]);
			}
			i++;
		}
		return(a);
}

char *checkcheckr(char *a, char **c, t_f *q, int s)
{
	struct stat st;
	long time;
	char **ff;
	int t;
	int f;
	int h;
	int k;

	k = 0;
	h = 1;
	f = 1;
	t = q[0].t;
	stat(a, &st);
	time = st.st_mtime;
	while (t < s)
	{
		stat(add(q[0].path, c[t]), &st);
		if (st.st_mtime == time)
		{
			f++;
		}
		t++;
	}
	t = q[0].t;
	ff = (char **)malloc(sizeof(char *) *  f);
	ff[0] = ft_strdup(q[0].a);
	while (t < s)
	{
		stat(add(q[0].path, c[t]), &st);
		if (st.st_mtime == time)
		{
			ff[h] = ft_strdup(c[t]);
			h++;
		}
		t++;
	}
	q[0].a = sortcheckr(ff, q, f);
	return (q[0].a);
}

int			whilerevtime(t_f *q, int s, char **c, struct stat filestat)
{
	long	time;
	long	ttime;

	ttime = 0;
	while (q[0].t < s)
	{
		stat(add(q[0].path, c[q[0].t]), &filestat);
		time = filestat.st_mtime;
		q[q[0].t].time = time;
		if (ttime == 0)
		{
			q[0].a = ft_strdup(c[q[0].t]);
			ttime = time;
		}
		else if (time < ttime)
		{
			q[0].a = ft_strdup(c[q[0].t]);
			ttime = time;
		}
		else if (time == ttime)
			q[0].a = checkcheckr(add(q[0].path, c[q[0].t]), c, q, s);
		q[0].t++;
	}
	return (s);
}

int		checktime(t_f *q, char *a, char *b)
{
	struct stat filestat;
	long timea;
	long timeb;

ft_putstr(a);
ft_putstr(b);
	stat(add(q[0].path, a), &filestat);
	timea = filestat.st_mtimespec.tv_nsec;
	stat(add(q[0].path, b), &filestat);
	timeb = filestat.st_mtimespec.tv_nsec;
	if (timea > timeb)
		ft_putstr("timea");
	else
		ft_putstr("timeb");
	return(0);
}

char *sortcheck(char **ff, t_f *q, int f)
{
	int i;
	char *a;
	struct stat attr;
	long ttime;
	long time;

	i = 1;
	ttime = getFileCreationTime(add(q[0].path, ff[0]));
	a = ft_strdup(ff[0]);
		while (i < f)
		{
			time = getFileCreationTime(add(q[0].path, ff[i]));
			if (ttime < time)
			{
			ttime = time;
			a = ft_strdup(ff[i]);
			}
			i++;
		}
		return(a);
}

char *checkcheck(char *a, char **c, t_f *q, int s)
{
	struct stat st;
	long time;
	char **ff;
	int t;
	int f;
	int h;
	int k;

	k = 0;
	h = 1;
	f = 1;
	t = q[0].t;
	stat(a, &st);
	time = st.st_mtime;
	while (t < s)
	{
		stat(add(q[0].path, c[t]), &st);
		if (st.st_mtime == time)
				f++;
		t++;
	}
	t = q[0].t;
	ff = (char **)malloc(sizeof(char *) *  f);
	ff[0] = ft_strdup(q[0].a);
	while (t < s)
	{
		stat(add(q[0].path, c[t]), &st);
		if (st.st_mtime == time)
		{
			ff[h] = ft_strdup(c[t]);
			h++;
		}
		t++;
	}
	q[0].a = sortcheck(ff, q, f);
	return (q[0].a);
}

int			whilettime(t_f *q, int s, char **c, struct stat filestat)
{
	long	time;
	long	ttime;

	ttime = 0;
	char *m;
	while (q[0].t < s)
	{
		stat(add(q[0].path, c[q[0].t]), &filestat);
		time = filestat.st_mtime;
		q[q[0].t].time = time;
		if (ttime == 0)
		{
			q[0].a = ft_strdup(c[q[0].t]);
			ttime = time;
		}
		else if (time > ttime)
		{
			q[0].a = ft_strdup(c[q[0].t]);
			ttime = time;
		}
		else if (time == ttime)
			q[0].a = checkcheck(add(q[0].path, c[q[0].t]), c, q, s);			
		q[0].t++;
	}
	return (s);
}
