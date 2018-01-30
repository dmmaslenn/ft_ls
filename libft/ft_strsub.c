/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:38:26 by dmaslenn          #+#    #+#             */
/*   Updated: 2016/12/06 15:21:58 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned long	i;
	char			*d;

	i = 0;
	d = NULL;
	if (!s)
		return (0);
	d = (char *)malloc(sizeof(char) * len + 1);
	if (d)
	{
		while (i < len)
		{
			d[i] = s[start];
			i++;
			start++;
		}
		d[i] = '\0';
		return (d);
	}
	else
		return (NULL);
}
