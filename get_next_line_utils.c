/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:43:11 by gusgonza          #+#    #+#             */
/*   Updated: 2024/05/12 16:02:22 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Calcula la longitud de una cadena de caracteres.
 *
 * @param s La cadena de caracteres de la cual se desea calcular la longitud.
 * @return La longitud de la cadena de caracteres.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * Obtiene una subcadena de una cadena de caracteres.
 *
 * @param s La cadena de caracteres de la cual se desea obtener la subcadena.
 * @param start La posición de inicio de la subcadena.
 * @param len La longitud de la subcadena.
 * @return La subcadena obtenida.
 */
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	pos;
	char	*substr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = (char *) malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	pos = 0;
	while (pos < len)
	{
		substr[pos] = s[start + pos];
		pos++;
	}
	substr[pos] = '\0';
	return (substr);
}

/**
 * Duplica una cadena de caracteres.
 *
 * @param source La cadena de caracteres que se desea duplicar.
 * @return La cadena de caracteres duplicada.
 */
char	*ft_strdup(const char *source)
{
	char	*destination;
	size_t	len;
	size_t	pos;

	if (!source)
		return (NULL);
	len = ft_strlen(source);
	destination = (char *) malloc((len + 1) * sizeof(char));
	if (!destination)
		return (NULL);
	pos = 0;
	while (source[pos] != '\0')
	{
		destination[pos] = source[pos];
		pos++;
	}
	destination[pos] = '\0';
	return (destination);
}

/**
 * Concatena dos cadenas de caracteres.
 *
 * @param s1 La primera cadena de caracteres.
 * @param s2 La segunda cadena de caracteres.
 * @return La cadena de caracteres resultante de la concatenación.
 */
char	*ft_strjoin(char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * ((i + j) + 1));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	res[i + j] = '\0';
	while (j--)
		res[i + j] = s2[j];
	while (i--)
		res[i] = s1[i];
	free(s1);
	return (res);
}

/**
 * Busca la primera aparición de un carácter en una cadena de caracteres.
 *
 * @param s La cadena de caracteres en la cual se desea buscar.
 * @param c El carácter que se desea buscar.
 * @return Un puntero a la primera aparición del carácter en la cadena, o NULL si no se encuentra.
 */
char	*ft_strchr(char *s, int c)
{
	unsigned int	pos;

	pos = 0;
	while (s[pos])
	{
		if (s[pos] == (char) c)
			return ((char *) &s[pos]);
		pos++;
	}
	if (s[pos] == (char)c)
		return ((char *) &s[pos]);
	return (NULL);
}
