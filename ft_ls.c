/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 18:09:09 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/05/17 17:05:26 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					count(char *path, t_dbl *list)
{
	DIR				*dir;
	struct dirent	*pdir;
	int				i;
	int				f;

	i = 0;
	f = 0;
	dir = opendir(path);
	if (dir == NULL)
		return (0);
	while ((pdir = readdir(dir)) != NULL)
	{
		if (list->a == 0 && pdir->d_name[0] == '.')
			f++;
		else
			i++;
	}
	closedir(dir);
	return (i);
}

int					counttotal(char *path, t_dbl *list)
{
	DIR				*dir;
	struct dirent	*pdir;
	int				total;
	struct stat		filestat;
	int				f;

	total = 0;
	f = 0;
	dir = opendir(path);
	if (dir == NULL)
		return (0);
	while ((pdir = readdir(dir)) != NULL)
	{
		if (list->a == 0 && pdir->d_name[0] == '.')
			f++;
		else
		{
			stat(add(path, pdir->d_name), &filestat);
			total += filestat.st_blocks;
		}
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
	return (0);
}

int		minmaj(t_f *d)
{
	struct stat filestat;
	int i;
	int mmaj;

	i = 1;
	mmaj = 0;
	d[0].rmmin = 0;
	while (i < d[0].i + 1)
	{
		stat(add(d[0].path, d[i].name), &filestat);
		if (S_ISCHR(filestat.st_mode) || S_ISBLK(filestat.st_mode)) {
        	d[i].maj = major(filestat.st_rdev);
        	d[i].rmaj = rank(d[i].maj);
        	if (d[i].rmaj > mmaj)
        		mmaj = d[i].rmaj;
        	d[i].min = minor(filestat.st_rdev);
        	d[i].rmin = rank(d[i].min);
        	if (d[i].rmin > d[0].rmmin)
        		d[0].rmmin = d[i].rmin;
    	}
    	else {
        	d[i].maj = -1;
        	d[i].min = -1;
    	}
    	i++;
	}
	return (mmaj);
}

int		checkwheel(t_f *d)
{
	struct stat filestat;
	struct group	*grp;
	int i;
	int k;

	i = 1;
	k = 0;
	while (i < d[0].i  + 1)
	{
		stat(add(d[0].path, d[i].name), &filestat);
		grp = getgrgid(filestat.st_gid);
		d[i].wl = ft_strlen(grp->gr_name);
		if (ft_strlen(grp->gr_name) > k)
			k = ft_strlen(grp->gr_name);
		i++;
	}
	return (k);
}

t_f					*maked(char *path, t_dbl *list)
{
	t_f				*d;
	int i;

	list->aa = 0;
	list->bb = 0;
	list->ii = 0;
	i = 1;
	d = (t_f *)malloc(sizeof(t_f) * (count(path, list) + 1));
	if (d == NULL)
		return (0);
	d[0].id = 0;
	d[0].i = count(path, list);
	if (list->l == 1 && d[0].i > 0)
		counttotal(path, list);
	d[0].path = ft_strdup(path);
	d = readd(d, list);
	while (i < d[0].i + 1)
	{
		d[i].denied = checkifdenied(add(path, d[i].name));
		i++;
	}
	d[0].wl = checkwheel(d);
	d[0].rmmaj = minmaj(d);
	if (d[0].i > 0)
		checkprivilege(d, d[0].i);
	return (d);
}

int					letsprintit(t_dbl *list)
{
	int				c;

	c = 1;
	while (c < list->tail->d[0].i + 1)
	{
		if (list->l == 1)
			statt(list, c);
		else
		{
			ft_putstr(list->tail->d[c].name);
			ft_putchar('\n');
		}
		c++;
	}
	return (0);
}

t_dbl				*letsdoit(char *path, t_dbl *list)
{
	t_node			*tmp;
	int				c;

	c = 1;
	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->d = maked(path, list);
	tmp->next = NULL;
	if (list->head == NULL)
	{
		list->head = tmp;
		list->tail = tmp;
	}
	else
		addit(list, tmp);
	list->tail->d[0].r1 = 0;
	list->tail->d[0].r = 0;
	ssizee(list);
	ssize(list);
	letsprintit(list);
	if (list->rbf == 1)
		folder(list);
	return (list);
}
