/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:21:01 by finoment          #+#    #+#             */
/*   Updated: 2026/03/01 16:17:32 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		lens;
	char	*dup;

	lens = 0;
	while (s[lens] != 0)
		lens++;
	dup = (char *) malloc(sizeof(char) * (lens + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < lens)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = "\0";
	str = (char *)(malloc(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		s = "\0";
	while (s[i] != '\0')
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		s++;
	}
	if ((unsigned char) c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}

char	*ft_get_line(char **stash)
{
	int		i;
	int		j;
	char	*line;
	char	*tmp;

	if (!stash || !*stash || !**stash)
		return (NULL);
	tmp = *stash;
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = -1;
	while (++j < i)
		line[j] = tmp[j];
	line[j] = '\0';
	*stash = ft_strdup(tmp + i);
	free(tmp);
	return (line);
}
