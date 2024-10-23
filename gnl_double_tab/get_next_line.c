/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:09:41 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/23 21:27:48 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*delete_part_of_stash(char *stash)
{
	int		i;
	int		j;
	char	*temp;

	i = ft_strlen(stash);
	j = 0;
	temp = malloc(sizeof(char) * (real_len(stash) - i + 1));
	while (stash[i])
	{
		temp[j] = stash[i];
		i++;
		j++;
	}
	temp[j] = '\0';
	free(stash);
	return (temp);
}

static char	*save_stash(char *buffer, char *stash, int ibuff)
{
	int	istash;

	istash = 0;
	if (stash)
		free(stash);
	stash = malloc(sizeof(char) * (BUFFER_SIZE - ft_strlen(buffer) + 1));
	if (stash == NULL)
		return (NULL);
	ibuff++;
	while (buffer[ibuff])
	{
		stash[istash] = buffer[ibuff];
		ibuff++;
		istash++;
	}
	stash[istash] = '\0';
	return (stash);
}

static char	*check_buffer(char *buffer, char *line)
{
	int	ibuff;

	ibuff = 0;
	while (buffer[ibuff])
	{
		if (buffer[ibuff] == '\n')
		{
			line = ft_strjoin(line, buffer);
			if (line == NULL)
				return (NULL);
			return (line);
		}
		ibuff++;
	}
	line = ft_strjoin(line, buffer);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			isread;

	isread = 1;
	line = NULL;
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > 1024 || fd < 0 || fd > 1024)
		return (NULL);
	if (BUFFER_SIZE > 1 || stash[fd])
	{
		line = ft_strjoin(line, stash[fd]);
	}
	if (line && line[ft_strlen(line)] == '\n')
	{
		stash[fd] = delete_part_of_stash(stash[fd]);
		return (line);
	}
	while (isread)
	{
		isread = read(fd, buffer, BUFFER_SIZE);
		if (isread <= 0 || !*buffer)
		{
			if (stash[fd])
				free(stash[fd]);
			if (line && isread == 0)
				return (line);
			return (NULL);
		}
		buffer[isread] = '\0';
		line = check_buffer(buffer, line);
		if (isread < BUFFER_SIZE || ft_strlen(buffer) < BUFFER_SIZE)
		{
			isread = 0;
			if (BUFFER_SIZE > 1 || ft_strlen(buffer) > 1)
				stash[fd] = save_stash(buffer, stash[fd], ft_strlen(buffer));
		}
	}
	return (line);
}
