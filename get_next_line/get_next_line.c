/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:46:16 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/24 13:27:06 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*read_line(int fd, char *stash)
{
	char	*buffer;
	ssize_t	isread;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	isread = 1;
	while (isread > 0)
	{
		isread = read(fd, buffer, BUFFER_SIZE);
		if (isread == -1)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[isread] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

static	char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			break ;
		i++;
	}
	line = ft_substr(stash, 0, i + 1);
	return (line);
}

static	char	*new_stash(char *s)
{
	int		i;
	char	*stash;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	if (s)
	{
		stash = ft_substr(s, i + 1, ft_strlen(s));
		free(s);
	}
	else
	{
		stash = malloc(sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = extract_line(stash);
	stash = new_stash(stash);
	if (line == NULL)
		free(stash);
	return (line);
}
