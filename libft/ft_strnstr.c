/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:57:20 by dmaslenn          #+#    #+#             */
/*   Updated: 2016/12/08 16:49:12 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *litt, size_t len)
{
	size_t i;
	size_t k;

	i = 0;
	if (!*litt)
		return ((char *)big);
	while (big[i])
	{
		k = 0;
		if (!len)
			return (NULL);
		while ((big[i + k] == litt[k]) && ((len - 1) >= k))
		{
			if (!litt[k + 1])
				return ((char *)big + i);
			k++;
		}
		len--;
		i++;
	}
	return (NULL);
}
