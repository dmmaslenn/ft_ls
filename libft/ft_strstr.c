/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:54:26 by dmaslenn          #+#    #+#             */
/*   Updated: 2016/11/28 13:14:14 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strstr(const char *big, const char *litt)
{
	int i;
	int k;

	i = 0;
	if (!*litt)
		return ((char *)big);
	while (big[i])
	{
		k = 0;
		while (big[i + k] == litt[k])
		{
			if (!litt[k + 1])
				return ((char *)big + i);
			k++;
		}
		i++;
	}
	return (0);
}
