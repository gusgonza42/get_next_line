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

/**
 * @brief Establece la línea en el búfer de línea y devuelve los caracteres restantes.
 * 
 * Esta función busca el carácter de nueva línea ('\n') o el final de la cadena ('\0')
 * en el búfer de línea. Luego extrae los caracteres restantes después del carácter de nueva línea
 * y los devuelve como una nueva cadena. Si el búfer de línea no contiene un carácter de nueva línea,
 * devuelve NULL.
 * 
 * @param line_buffer El búfer de línea a procesar.
 * @return Un puntero a los caracteres restantes después del carácter de nueva línea, o NULL si no hay un carácter de nueva línea.
 */

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

/**
 * @brief Lee datos del descriptor de archivo y los agrega a la cadena de almacenamiento.
 * 
 * Esta función lee datos del descriptor de archivo en fragmentos de tamaño BUFFER_SIZE.
 * Agrega los datos leídos a la cadena de almacenamiento, que contiene los caracteres acumulados
 * de lecturas anteriores. Si se encuentra un carácter de nueva línea durante la lectura, la función se detiene
 * la lectura y devuelve la cadena de almacenamiento. Si se produce un error durante la lectura, la función libera
 * la cadena de almacenamiento y devuelve NULL.
 * 
 * @param fd El descriptor de archivo del que leer.
 * @param stash_c La cadena de almacenamiento que contiene los caracteres acumulados.
 * @param buffer El búfer para almacenar los datos leídos.
 * @return La cadena de almacenamiento si se encuentra un carácter de nueva línea, o NULL si se produce un error.
 */

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

/**
 * @brief Lee la siguiente línea del descriptor de archivo.
 * 
 * Esta función lee la siguiente línea del descriptor de archivo especificado por fd.
 * Utiliza una variable estática stash para almacenar los caracteres acumulados de lecturas anteriores.
 * La función asigna memoria para un búfer para almacenar los datos leídos. Si el descriptor de archivo no es válido,
 * la asignación de búfer falla o se produce un error durante la lectura, la función libera la memoria asignada
 * y devuelve NULL. De lo contrario, llama a ft_line_buffer para leer y agregar datos a la cadena de almacenamiento.
 * Finalmente, establece la línea llamando a ft_set_line y devuelve la línea.
 * 
 * @param fd El descriptor de archivo del que leer.
 * @return La siguiente línea leída del descriptor de archivo, o NULL si se produce un error.
 */

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
