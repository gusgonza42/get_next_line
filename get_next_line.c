/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:42:59 by gusgonza          #+#    #+#             */
/*   Updated: 2024/05/01 19:18:11 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	buffer = (char *) malloc((BUFFER_SIZE +1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = ft_read_line(fd, stash, buffer);
	if (!line)
		return (NULL);
	stash = ft_stash_clean(line);
	return (line);
}
