/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:09:41 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/18 21:21:30 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_buffer(char *buffer, char **stash, char *line, int iline, int fd)
{
	int ibuff;
	int istash;
	int max;

	ibuff = 0;
	istash = 0;
	max = ft_strlen(line) + ft_strlen(buffer) + 1;
	line = malloc(sizeof(char) * max);
	if (line == NULL)
		return (NULL);
	line[max] = '\0';
	while (buffer[ibuff])
	{
		if (buffer[ibuff] == '\n') // mettre l'interieur de cette condition dans une fonction "save_stash"
		{
			stash[fd] = malloc(sizeof(char) * (BUFFER_SIZE - ft_strlen(buffer)));
			if (stash[fd] == NULL)
				return (NULL);
			while (buffer[ibuff])
				{
					stash[fd][istash] = buffer[ibuff];
					ibuff++;
					istash++;
					return (0);
				}
		}
		line = ft_strjoin(line, buffer);
	}
	return (1);
}

int	add_stash(char *stash, char *line, int fd)
{
	int iline;
	int istash;

	iline = 0;
	istash = 0;
	while (stash[istash])
	{
		line[iline] = stash[istash];
		istash++;
		iline++;
	}
	return (iline);
}

char	*get_next_line(int fd)
{
	static char *stash[1024];
	char buffer[BUFFER_SIZE + 1];
	char *line;
	int isread;
	int iline;

	iline = 0;
	isread = 1;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (stash[fd])
		iline = add_stash(stash, line, fd);
	while (isread)
	{
		isread = read(fd, buffer, BUFFER_SIZE);
		if (isread < 0 || !buffer)
			return (NULL);
		buffer[BUFFER_SIZE + 1] = '\0';
		if (check_buffer(buffer, stash, line, iline, fd) == 0)
			isread = 0;
	}
	return (line);
}
