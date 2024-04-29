/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:43:11 by gusgonza          #+#    #+#             */
/*   Updated: 2024/04/29 18:32:33 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			total_len;
	unsigned char	*byte_ptr;

	total_len = nmemb * size;
	ptr = (char *)malloc(total_len);
	if (!ptr)
		return (NULL);
	byte_ptr = (unsigned char *)ptr;
	while (total_len--)
		*byte_ptr++ = 0;
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}


