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
		return (malloc(1));
	if (len > ft_strlen(s + star))
		len = ft_strlen(s + star);
	substr = (char *) malloc((len +1) * sizeof(char));
	if (!substr)
		return (NULL);
	pos = 0;
	while (pos < len)
	{
		substr[pos] = s[start + 1];
		pos++;
	}
	substr[pos] = '\0';
	return (substr);
}

char	*ft_strdup(char *source)
{
	char	*destination;
	size_t	pos;

	destination = (char *) malloc ((ft_strlen(source) + 1) * sizeof(char));
	if (!destination)
		return (NULL);
	pos = 0;
	while (source[pos])
	{
		destination[pos] = source[pos];
		pos++;
	}
	destination[pos] = '\0';
	return (destination);
}

char	*ft_strjoin(char *sL, char *sR)
{
	char	*res;

	res = (char *) malloc((ft_strlen(sL) + ft_strlen(sR) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	fill_str(res, sL, sR);
	return (res);
}

void	fill_str(char *result, char *str1, char *str2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
}
