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

// Función para liberar la memoria de una cadena y establecerla en NULL
char	*ft_str_free_and_null(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

// Función para limpiar el almacenamiento después de leer una línea
char	*ft_str_remove_line(char *storage)
{
	char	*new_storage;
	char	*newline;
	int		len;

	newline = ft_strchr(storage, '\n');
	if (!newline)
		return (ft_str_free_and_null(&storage));
	else
		len = (newline - storage) + 1;
	if (!storage[len])
		return (ft_str_free_and_null(&storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	ft_str_free_and_null(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

// Función para obtener la línea fresca (hasta el carácter de nueva línea) desde el almacenamiento
char	*ft_str_get_line(char *storage)
{
	char	*line;
	char	*newline;
	int		len;

	newline = ft_strchr(storage, '\n');
	len = (newline - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

// Función para leer datos desde un archivo descriptor
char	*ft_str_read_data(int fd, char *storage)
{
	int		ret;
	char	*buf;

	ret = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_str_free_and_null(&storage));
	buf[0] = '\0';
	while (ret > 0 && !ft_strchr(buf, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret > 0)
		{
			buf[ret] = '\0';
			storage = ft_strjoin(storage, buf);
		}
	}
	free(buf);
	if (ret == -1)
		return (ft_str_free_and_null(&storage));
	return (storage);
}

// Función principal para obtener la próxima línea desde un archivo descriptor
char	*get_next_line(int fd)
{
	static char	*storage = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((storage && !ft_strchr(storage, '\n')) || !storage)
		storage = ft_str_read_data(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_str_get_line(storage);
	if (!line)
		return (ft_str_free_and_null(&storage));
	storage = ft_str_remove_line(storage);
	return (line);
}
