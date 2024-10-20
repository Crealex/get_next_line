/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:09:41 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/20 19:45:08 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*save_stash(char *buffer, char *stash, int ibuff)
{
	int	istash;

	istash = 0;
	printf("stash dans debut de save_stash : %s\n", stash);
	if (BUFFER_SIZE == real_len(buffer))
		stash = malloc(sizeof(char) * (BUFFER_SIZE - ft_strlen(buffer)));
	if (stash == NULL)
		return (NULL);
	ibuff++;
	while (buffer[ibuff])
	{
		stash[istash] = buffer[ibuff];
		ibuff++;
		istash++;
	}
	printf("stash dans fin de save_stash : %s\n", stash);
	return (stash);
}

static char	*check_buffer(char *buffer, char *stash, char *line)
{
	int	ibuff;

	ibuff = 0;
	while (buffer[ibuff])
	{
		if (buffer[ibuff] == '\n')
		{
			stash = save_stash(buffer, stash, ibuff);
			printf("stash dans check_buffer : %s\n", stash);
			line = ft_strjoin(line, buffer);
			return (line);
		}
		ibuff++;
	}
	line = ft_strjoin(line, buffer);
	return (line);
}

static char	*add_stash(char *stash, char *line)
{
	int	iline;
	int	istash;

	iline = 0;
	istash = 0;
	printf("stash add_stash : %s\n", stash);
	while (stash[istash])
	{
		line[iline] = stash[istash];
		istash++;
		iline++;
	}
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
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (stash[fd])
	{
		printf("stash dans principal : %s\n", stash[fd]);
		line = add_stash(stash[fd], line);
	}
	while (isread)
	{
		isread = read(fd, buffer, BUFFER_SIZE);
		if (isread < 0 || !*buffer)
			return (NULL);
		buffer[isread] = '\0';
		line = check_buffer(buffer, stash[fd], line);
		printf("stash a la fin de la fonction principal : %s\n", stash[fd]);
		if (isread < BUFFER_SIZE || ft_strlen(buffer) < BUFFER_SIZE)
			{
				isread = 0;
			}
	}
	return (line);
}
