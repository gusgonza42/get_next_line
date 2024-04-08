/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:04:00 by gusgonza          #+#    #+#             */
/*   Updated: 2024/04/08 14:04:02 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("yowTest.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error open\n");
		return (1);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		if (str == NULL)
			printf("Error dont read line");
		else
		{
			printf("Result line: %s \n", str);
			free(str);
		}
	}

	close(fd);

	return (0);
}

