/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:13:59 by dmaslenn          #+#    #+#             */
/*   Updated: 2016/12/05 12:15:37 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *d;

	d = (char *)malloc(sizeof(char) * size);
	if (d == NULL)
		return (0);
	ft_bzero(d, size);
	return (d);
}
