/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:43:23 by gusgonza          #+#    #+#             */
/*   Updated: 2024/05/01 17:15:56 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *source);
char	*ft_strjoin(char *sL, char *sR);
void	fill_str(char *result, char *str1, char *str2);
size_t	ft_strlen(const char *s);

#endif
