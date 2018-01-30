/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:38:51 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/02/08 15:01:02 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int				check(char *s4)
{
	int			c;

	c = 0;
	while (s4[c])
	{
		if (s4[c] == '\n')
			return (c);
		c++;
	}
	return (-1);
}

char			*leha(char *s3, int i, char **line)
{
	char		*ebala;
	char		*xuy;

	ebala = ft_strsub(s3, 0, i);
	*line = ebala;
	xuy = ft_strsub(s3, i + 1, ft_strlen(s3));
	free(s3);
	return (xuy);
}

int				h(char **s3, int fd, char **line)
{
	char		*buf;
	char		*s4;
	int			r;

	s4 = ft_strnew(BUFF_SIZE);
	r = read(fd, s4, BUFF_SIZE);
	if (r == 0)
	{
		if (ft_strlen(*s3) > 0)
		{
			*line = ft_strsub(*s3, 0, ft_strlen(*s3));
			*s3 = ft_strnew(0);
			return (1);
		}
		return (0);
	}
	else if (r < 0)
		return (-1);
	buf = *s3;
	*s3 = ft_strjoin(*s3, s4);
	free(buf);
	free(s4);
	return (2);
}

int				get_next_line(int fd, char **line)
{
	static char	*s3;
	int			r;

	r = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	else if (!s3)
		s3 = ft_strnew(0);
	while (check(s3) < 0)
	{
		r = h(&s3, fd, line);
		if (r != 2)
			return (r);
		if (r == 1)
			return (r);
	}
	if (check(s3) >= 0)
	{
		s3 = leha(s3, check(s3), line);
		return (1);
	}
	return (r);
}
