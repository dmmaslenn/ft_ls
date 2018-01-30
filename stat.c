/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:24:49 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/05/16 17:06:50 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

int				finishstat(struct stat filestat, char *timebuf,\
					t_dbl *list, int i)
{
	ft_putchar(' ');
	ft_putstr(ft_strsub(timebuf, 4, 12));
	ft_putchar(' ');
	ft_putstr(list->tail->d[i].name);
	ft_putchar('\n');
	return (0);
}

int		setminmaj(t_dbl *list, int i, struct stat filestat)
{
	int c;

	c = list->tail->d[0].rmmaj - list->tail->d[i].rmaj;
	while (c > -1)
	{
		ft_putchar (' ');
		c--;
	}
	if (list->tail->d[i].maj == -1){
		c = list->tail->d[0].rmmaj - 1 + list->tail->d[0].rmmin - list->tail->d[i].r1;
		while (c > -1)
		{
			ft_putchar (' ');
			c--;
		} 
		ft_putnbr((int)filestat.st_size);
	}
	else{
	ft_putnbr(list->tail->d[i].maj);
	ft_putchar (',');
	c = list->tail->d[0].rmmin - list->tail->d[i].rmin;
	while (c > -1)
	{
		ft_putchar (' ');
		c--;
	}
	ft_putnbr(list->tail->d[i].min);}
	return (0);
}

int				statt(t_dbl *list, int i)
{
	struct stat filestat;
	int			w;
	struct tm	ttime;
	time_t		time;
	char		timebuf[80];
	int c;

	w = -1;
	stat(add(list->tail->d[0].path, list->tail->d[i].name), &filestat);
	time = filestat.st_mtime;
	localtime_r(&time, &ttime);
	strftime(timebuf, sizeof(timebuf), "%c", &ttime);
	chmood(filestat, list, i);
	setattr(list, i);
	while (w++ < list->tail->d[0].r1 - list->tail->d[i].r1 )
		ft_putchar(' ');
	w = -1;
	whatevs(filestat);
	c = list->tail->d[0].wl - list->tail->d[i].wl;
	while (c > -1)
	{
		ft_putchar(' ');
		c--;
	}
	if (list->tail->d[0].rmmaj != 0)
		setminmaj(list, i, filestat);
	else
	{	
		while (w++ < list->tail->d[0].r - list->tail->d[i].r)
			ft_putchar(' ');
		ft_putnbr((int)filestat.st_size);
	}
	finishstat(filestat, timebuf, list, i);
	return (0);
}

int				rank(int i)
{
	int			r;

	r = 0;
	while (i / 10 >= 1)
	{
		i = i / 10;
		r++;
	}
	r++;
	return (r);
}

int				ssizee(t_dbl *list)
{
	struct stat filestat;
	int			i;
	int			size;

	i = 1;
	size = 0;
	while (i < list->tail->d[0].i + 1)
	{
		stat(add(list->tail->d[0].path, list->tail->d[i].name), &filestat);
		size = (int)filestat.st_nlink;
		if (rank(size) > list->tail->d[0].r1)
			list->tail->d[0].r1 = rank(size);
		list->tail->d[i].r1 = rank(size);
		i++;
	}
	return (0);
}

int				ssize(t_dbl *list)
{
	struct stat filestat;
	int			i;
	int			size;

	i = 1;
	size = 0;
	while (i < list->tail->d[0].i + 1)
	{
		stat(add(list->tail->d[0].path, list->tail->d[i].name), &filestat);
		size = (int)filestat.st_size;
		if (rank(size) > list->tail->d[0].r)
			list->tail->d[0].r = rank(size);
		list->tail->d[i].r = rank(size);
		i++;
	}
	return (0);
}
