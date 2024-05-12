/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:42:59 by gusgonza          #+#    #+#             */
/*   Updated: 2024/05/12 17:00:53 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_set_line(char *line_buffer)
{
	char	*stash_c;
	size_t	pos;

	pos = 0;
	while (line_buffer[pos] != '\n' && line_buffer[pos] != '\0')
		pos++;
	if (line_buffer[pos] == 0)
		return (NULL);
	stash_c = ft_substr(line_buffer, pos + 1, ft_strlen(line_buffer) - pos);
	if (!stash_c)
		return (NULL);
	if (*stash_c == 0)
	{
		free(stash_c);
		stash_c = NULL;
	}
	line_buffer[pos + 1] = 0;
	return (stash_c);
}

static char	*ft_line_buffer(int fd, char *stash_c, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(stash_c);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		tmp = ft_strdup(stash_c);
		free(stash_c);
		stash_c = ft_strjoin(tmp, buffer);
		if (!stash_c)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash_c);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		free(stash);
		free(buffer);
		stash = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = ft_line_buffer(fd, stash, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stash = ft_set_line(line);
	return (line);
}
