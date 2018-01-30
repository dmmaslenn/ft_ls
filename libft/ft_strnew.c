/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:21:54 by dmaslenn          #+#    #+#             */
/*   Updated: 2016/12/05 17:46:34 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str)
	{
		while (size != 0)
		{
			str[i] = '\0';
			i++;
			size--;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
