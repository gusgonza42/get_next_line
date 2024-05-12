/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:43:11 by gusgonza          #+#    #+#             */
/*   Updated: 2024/05/12 12:45:24 by gusgonza         ###   ########.fr       */
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

char	*ft_strjoin(const char *sL, const char *sR)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (sL == NULL)
		sL = "";
	res = (char *)malloc(sizeof(char) * (ft_strlen(sL) + ft_strlen(sR) + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (sL[++i] != '\0')
		res[i] = sL[i];
	j = -1;
	while (sR[++j] != '\0')
		res[i + j] = sR[j];
	res[i + j] = '\0';
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
