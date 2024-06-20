/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:42:59 by gusgonza          #+#    #+#             */
/*   Updated: 2024/06/20 22:36:46 by gusgonza         ###   ########.fr       */
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
	static char	*stash[fd];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD || read(fd, 0, 0) == -1)
	{
		if (fd >= 0 && fd < MAX_FD)
		{
			free(stash[fd]);
			free(buffer);
			stash[fd] = NULL;
			buffer = NULL;
		}
		return (NULL);
	}
	line = ft_line_buffer(fd, stash[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stash[fd] = ft_set_line(line);
	return (line);
}

#include <stdio.h>

int	main(void)
{
	int fd1, fd2;
	char *line1, *line2;

	fd1 = open ("yow.txt", O_RDONLY);
	fd2 = open ("chat.txt", O_RDONLY);
	while ((line1 = get_next_line(fd1)) != NULL || (line2 = get_next_line(fd2)) != NULL)
	{
			if (line1)
				{
			printf("F1 line -> %s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("F2 line -> %s", line1);
			free(line1);
		}
	}
	close(fd1);
	close(fd2);
	return (0);
}
