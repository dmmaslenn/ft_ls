/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 15:41:16 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/05/16 17:07:12 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				**excludetime(char **d, char *c, int s)
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
	f = (char **)malloc(sizeof(char *) * s);
	while (k < i)
	{
		f[a] = ft_strdup(d[k]);
		a++;
		k++;
	}
	k++;
	while (a < s)
	{
		f[a] = ft_strdup(d[k]);
		a++;
		k++;
	}
	return (f);
}

t_f					*revttimme(t_f *q, char **c)
{
	struct stat		filestat;
	int				s;
	int				u;

	q[0].t = 0;
	u = 1;
	s = q[0].i;
	while (s != 0)
	{
		s = whilerevtime(q, s, c, filestat);
		s--;
		q[u].name = ft_strdup(q[0].a);
		checkprivilege(q, u);
		u++;
		c = excludetime(c, q[0].a, s);
		q[0].t = 0;
	}
	return (q);
}


t_f					*ttimme(t_f *q, char **c)
{
	struct stat		filestat;
	int				s;
	int				u;

	q[0].t = 0;
	u = 1;
	s = q[0].i;
	while (s != 0)
	{
		s = whilettime(q, s, c, filestat);
		s--;
		q[u].name = ft_strdup(q[0].a);
		checkprivilege(q, u);
		u++;
		c = excludetime(c, q[0].a, s);
		q[0].t = 0;
	}
	return (q);
}
