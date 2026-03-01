/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 11:52:14 by finoment          #+#    #+#             */
/*   Updated: 2026/03/01 16:05:47 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	static char		*stash;
	ssize_t			bytes;

	if (fd == -1 || BUFFER_SIZE + 0 <= 0)
		return (NULL);
	buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE + 0);
	while (!ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE + 0);
		if (bytes < 0)
		{
			free(stash);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	line = ft_get_line(&stash);
	return (line);
}
