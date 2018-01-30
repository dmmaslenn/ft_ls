/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:41:41 by dmaslenn          #+#    #+#             */
/*   Updated: 2016/12/05 12:13:42 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*d;

	i = 0;
	if (!s)
		return (NULL);
	d = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (d)
	{
		while (s[i])
		{
			d[i] = f(s[i]);
			i++;
		}
		d[i] = '\0';
		return (d);
	}
	else
		return (NULL);
}
