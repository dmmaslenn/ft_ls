/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:14:15 by dmaslenn          #+#    #+#             */
/*   Updated: 2016/12/08 16:48:32 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*printme(int n, char *d, int neg, int k)
{
	d[k] = '\0';
	if (n == 0)
		d[0] = 48;
	if (neg == 1)
	{
		neg = 0;
		d[0] = '-';
		d[--k] = (char)((n % 10) + 48 + 1);
		n = n / 10;
	}
	while (n > 0)
	{
		d[--k] = (char)((n % 10) + 48);
		n = n / 10;
	}
	return (d);
}

char			*ft_itoa(int n)
{
	int			k;
	int			neg;
	char		*d;
	int			i;

	k = 0;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = (-n) - 1;
		k++;
	}
	i = n;
	if (i == 0)
		k++;
	while (i > 0)
	{
		i = i / 10;
		k++;
	}
	if (!(d = (char *)malloc(sizeof(char) * k + 1)))
		return (NULL);
	return (printme(n, d, neg, k));
}
