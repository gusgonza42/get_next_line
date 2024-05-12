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
