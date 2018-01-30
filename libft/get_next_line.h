/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:03:07 by dmaslenn          #+#    #+#             */
/*   Updated: 2017/02/08 15:02:17 by dmaslenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# define BUFF_SIZE 100
# include <fcntl.h>
# include "libft.h"

int		get_next_line(int fd, char **line);

#endif
