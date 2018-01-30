/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:58:39 by dmaslenn          #+#    #+#             */
/*   Updated: 2016/12/05 12:22:41 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst1;
	unsigned char *src1;

	dst1 = dst;
	src1 = (unsigned char *)src;
	while (n)
	{
		*dst1++ = *src1++;
		n--;
	}
	return (dst);
}
