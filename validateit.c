/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validateit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 11:34:10 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/05/17 17:28:13 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		e(char **argv, int c, t_dbl *list, int i)
{
	if (argv[i][c + 1] == '\0')
		return (0);
	if (checkl(i, c + 1, argv, list) == 0)
		return (0);
	if (!argv[i + 1])
		return (0);
	return (1);
}

int		whilej(t_dbl *list, char **argv, int i, int c)
{
	int k;

	k = 1;
	while (argv[i][c] != '\0')
	{
		if (argv[i][c] == '-' && c == 0 && i == k)
		{
			k += 1;
			if (e(argv, c, list, i) == 0)
				return (0);
			i++;
			c = -1;
		}
		else if ((argv[i][c] == '-' && c == 0 && i != k) ||\
			(checkfolder(list, argv, i) == 0))
		{
			error(argv, i, list);
			if (!argv[i + 1])
				return (0);
			i++;
			c = -1;
		}
		c++;
	}
	return (i);
}

int		heeelp(t_dbl *list, int w)
{
	list->ff++;
	w++;
	return (w);
}
