/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:01:25 by dmaslenn          #+#    #+#             */
/*   Updated: 2016/12/08 16:37:01 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t s;
	size_t m;

	s = 0;
	m = 0;
	while (dst[m])
		m++;
	while (src[s] && (m + 1) < size)
		dst[m++] = src[s++];
	dst[m] = '\0';
	if (!s)
		m = size;
	while (src[s++])
		m++;
	return (m);
}
