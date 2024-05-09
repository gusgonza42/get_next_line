/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:43:11 by gusgonza          #+#    #+#             */
/*   Updated: 2024/05/01 19:05:49 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Función: ft_strjoin
** -----------------------
** Concatena dos cadenas (s1 y s2) en una nueva cadena.
**
** s1: La primera cadena a concatenar.
** s2: La segunda cadena a concatenar.
**
** Retorna: La cadena resultante de la concatenación de s1 y s2.
*/
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) + 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc((ft_str_len(s1) + ft_str_len(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (ft_str_delete(&s1));
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_str_len(s1) + ft_str_len(s2)] = '\0';
	free(s1);
	return (str);
}

/*
** Función: ft_str_len
** --------------------
** Calcula la longitud de una cadena.
**
** str: La cadena de la que se desea obtener la longitud.
**
** Retorna: La longitud de la cadena.
*/
size_t	ft_str_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
** Función: ft_str_chr
** --------------------
** Busca la primera aparición de un carácter en una cadena.
**
** s: La cadena en la que buscar.
** c: El carácter a buscar.
**
** Retorna: Un puntero a la primera aparición de 'c' en 's',
**          o NULL si 'c' no está presente en 's'.
*/
char	*ft_str_chr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

/*
** Función: ft_str_sub
** --------------------
** Crea una nueva cadena a partir de una subcadena de otra cadena.
**
** s: La cadena de origen.
** start: La posición inicial de la subcadena en 's'.
** len: La longitud de la subcadena.
**
** Retorna: La subcadena de 's' comenzando desde 'start' con longitud 'len'.
*/
char	*ft_str_sub(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_str_len(s))
	{
		res = malloc(sizeof(char) * (1));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (ft_str_len(s) - start < len)
		len = ft_str_len(s) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < ft_str_len(s) && i < len && s[start])
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
