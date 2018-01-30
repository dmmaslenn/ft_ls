/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:21:58 by dmaslenn          #+#    #+#             */
/*   Updated: 2016/12/05 12:32:27 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;
	char			c;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = -n;
	}
	else
		i = n;
	if (i <= 9)
	{
		c = i + '0';
		ft_putchar_fd(c, fd);
	}
	else
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
}
