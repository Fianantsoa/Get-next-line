/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 11:52:14 by finoment          #+#    #+#             */
/*   Updated: 2026/04/01 12:47:04 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*temp;
	static char		*stash;
	ssize_t			bytes;

	if (fd < 0 || BUFFER_SIZE + 0 <= 0)
		return (NULL);
	buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (!ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE + 0);
		if (bytes < 0)
		{
			free(stash);
			break ;
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
	}
	free(buffer);
	return (ft_get_line(&stash));
}
