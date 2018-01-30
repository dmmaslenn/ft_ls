/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 18:06:23 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/05/16 17:06:11 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			caseone(t_dbl *list, int c, char *cwd)
{
	while (c < list->w)
	{
		list->path = ft_strdup(list->q[c]);
		list->folder = ft_strdup(list->q[c]);
		if (list->w > 1 || list->error == 1)
		{
			ft_putstr(list->q[c]);
			ft_putstr(":\n");
		}
		if (list->q[c][0] != '/')
			letsdoit(add(cwd, list->q[c]), list);
		else
			letsdoit(list->q[c], list);
		c++;
		if (c != list->w)
			ft_putchar('\n');
	}
	return (0);
}

int			casetwo(t_dbl *list, int c, char *cwd)
{
	while (c > -1)
	{
		if (list->q[c][0] != '/')
			list->path = ft_strdup(add(cwd, list->q[c]));
		else
			list->path = ft_strdup(list->q[c]);
		list->folder = ft_strdup(list->q[c]);
		if (list->w > 1 || list->error == 1)
		{
			ft_putstr(list->q[c]);
			ft_putstr(":\n");
		}
		if (list->q[c][0] != '/')
			letsdoit(add(cwd, list->q[c]), list);
		else
			letsdoit(list->q[c], list);
		c--;
		if (c > -1)
			ft_putchar('\n');
	}
	return (0);
}

int			iff(t_dbl *list, char *cwd, int c)
{
	if (list->w != 0)
	{
		if (list->r == 1)
		{
			c = list->w - 1;
			casetwo(list, c, cwd);
		}
		else
			caseone(list, c, cwd);
	}
	else if (list->error != 1)
	{
		if (list->k != 1)
		{
			list->path = ft_strdup(cwd);
			list->folder = ft_strdup(".");
			letsdoit(cwd, list);
		}
	}
	return (0);
}

int			checkifdenied(char *path)
{
	struct stat filestat;
	char c;
	int i;

	i = 0;
	stat(path, &filestat);
	if ((filestat.st_mode & S_IWUSR) != 0)
		i = 1;
	if ((filestat.st_mode & S_IXUSR) != 0)
		i = 1;
	if ((filestat.st_mode & S_IRGRP) != 0)
		i = 1;
	if ((filestat.st_mode & S_IWGRP) != 0)
		i = 1;
	if ((filestat.st_mode & S_IXGRP) != 0)
		i = 1;
	if ((filestat.st_mode & S_IROTH) != 0)
		i = 1;
	if ((filestat.st_mode & S_IWOTH) != 0)
		i = 1;
	if ((filestat.st_mode & S_IXOTH) != 0)
		i = 1;
	return (i);
}

int			errorfolder(int argc, char **argv, t_dbl *list)
{
	int i;

	i = 0;
	list->ert = 0;
	list->err = 0;
	validationr(argc, argv, list);
	list->ert = 1;
	list->err = 0;
	list->c = (char **)malloc(sizeof(char *) * list->erf);
	list->erf = 0;
	validationr(argc, argv, list);
	list->c = sortr(list->c, list);
	while (i < list->erf)
	{
		ft_putstr("ls: ");
		ft_putstr(list->c[i]);
		if (checkifdenied(add(list->path, list->c[i])) == 0)
			ft_putstr(": Permission denied\n");
		else
			ft_putstr(": No such file or directory\n");
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_dbl	*list;
	char	cwd[1024];
	int		c;
	t_dbl *temp;

	c = 0;
	list = createlist();
	getcwd(cwd, sizeof(cwd));
	list->path = ft_strdup(cwd);
	list->erf = 0;
	list->a = 0;
	temp = list;
	errorfolder(argc, argv ,temp);
	validation(argc, argv, list);
	iff(list, cwd, c);
	return (0);
}

int			checktarget(char *c, char *cwd)
{
	DIR		*dir;

	dir = opendir(c);
	if (dir != NULL && c[0] == '/')
		return (1);
	dir = opendir(add(cwd, c));
	if (dir != NULL)
		return (2);
	return (0);
}
