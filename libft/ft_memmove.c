/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:43:17 by dmaslenn          #+#    #+#             */
/*   Updated: 2016/12/05 12:14:35 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buf;
	size_t			i;

	i = 0;
	buf = (unsigned char *)malloc(len);
	if (buf)
	{
		while (i < len)
		{
			buf[i] = ((unsigned char *)src)[i];
			i++;
		}
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = buf[i];
			i++;
		}
	}
	free(buf);
	return (dst);
}
