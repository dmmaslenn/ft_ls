/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:50:05 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/05/16 17:07:01 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			chmood(struct stat filestat, t_dbl *list, int i)
{
	if (list->tail->d[i].maj != -1)
		ft_putchar('c');
	else
		ft_putstr((S_ISDIR(filestat.st_mode)) ? "d" : "-");
	ft_putstr((filestat.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((filestat.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((filestat.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((filestat.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((filestat.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((filestat.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((filestat.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((filestat.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((filestat.st_mode & S_IXOTH) ? "x" : "-");
	return (0);
}

int			whatevs(struct stat filestat)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(filestat.st_uid);
	grp = getgrgid(filestat.st_gid);
	ft_putnbr(filestat.st_nlink);
	ft_putchar(' ');
	ft_putstr(pwd->pw_name);
	ft_putchar('\t');
	ft_putstr(grp->gr_name);
	return (0);
}

int			setattr(t_dbl *list, int i)
{
	ssize_t		xattr;

	xattr = listxattr(add(list->tail->d[0].path, list->tail->d[i].name),\
			NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		ft_putchar('@');
	else
		ft_putchar(' ');
	return (0);
}

char		*helper(t_dbl *list, int argc, char **argv, char *c)
{
	while (list->gg + 1 < argc - list->hh - 1)
	{
		if (!argv[list->gg + 1])
			break ;
		while (list->gg + 1 < argc - list->hh - 1)
		{
			if (!argv[list->gg + 1])
				break ;
			c = helpera(list, argc, argv, c);
		}
		if (argv[list->gg + 1][list->kk] == '\0')
		{
			c = strdup(argv[list->gg + 1]);
			break ;
		}
		else if (c[list->kk] == '\0')
			break ;
		list->kk = 0;
		list->gg++;
		if (!argv[list->gg + 1])
			break ;
	}
	return (c);
}

char		*helpera(t_dbl *list, int argc, char **argv, char *c)
{
	while ((list->gg + 1 < argc - list->hh - 1) && \
		(argv[list->gg + 1][list->kk] != '\0') && (c[list->kk] != '\0'))
	{
		if (c[list->kk] > argv[list->gg + 1][list->kk])
		{
			c = strdup(argv[list->gg + 1]);
			break ;
		}
		else if (c[list->kk] < argv[list->gg + 1][list->kk])
			break ;
		else
			list->kk++;
		if (!argv[list->gg + 1])
			break ;
	}
	return (c);
}
