/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:14:58 by dmaslenn          #+#    #+#             */
/*   Updated: 2016/12/05 12:28:48 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr(int n)
{
	unsigned int	i;
	char			c;

	if (n < 0)
	{
		ft_putchar('-');
		i = -n;
	}
	else
		i = n;
	if (i <= 9)
	{
		c = i + '0';
		ft_putchar(c);
	}
	else
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}
