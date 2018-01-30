/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:46:16 by dmaslenn          #+#    #+#             */
/*   Updated: 2016/12/06 15:22:42 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst1;
	unsigned char		*src1;
	int					a;

	a = 0;
	dst1 = dst;
	src1 = (unsigned char *)src;
	while (n != 0)
	{
		if (src1[a] == (unsigned char)c)
		{
			dst1[a] = src1[a];
			return (&dst1[a + 1]);
		}
		dst1[a] = src1[a];
		a++;
		n--;
	}
	return (NULL);
}
