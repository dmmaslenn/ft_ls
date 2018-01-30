/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:51:47 by dmaslenn          #+#    #+#             */
/*   Updated: 2016/11/22 16:15:30 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	s2 = (char *)malloc(sizeof(char) * i + 1);
	if (s2 == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		s2[k] = s1[i];
		k++;
		i++;
	}
	s2[k] = '\0';
	return (s2);
}
