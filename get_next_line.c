/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:42:59 by gusgonza          #+#    #+#             */
/*   Updated: 2024/04/08 13:43:01 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*buffer;
	size_t		size;

	size = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	storage = ft_read_fd(fd, buffer, storage);

	ft_read_fd(int fd, char *buffer, char *storage, size_t size)
	{
		if (fd < 0 || buffer == NULL)
			return (NULL);
		while (storage = read(fd,buffer + size) )
	}


	if (!storage)
		return (NULL);
	line = ft_create_line(storage);
	if(!line)
		return (NULL);
	storage = ft_update_storage(storage);
	if (!storage)
		return(NULL);
	return (line);
}
