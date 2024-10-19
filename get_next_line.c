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

static void	save_stash(char *buffer, char *stash, int ibuff)
{
	int	istash;

	istash = 0;
	if (BUFFER_SIZE == real_len(buffer))
		stash = malloc(sizeof(char) * (BUFFER_SIZE - ft_strlen(buffer)));
	if (stash == NULL)
		return ;
	while (buffer[ibuff])
	{
		stash[istash] = buffer[ibuff];
		ibuff++;
		istash++;
	}
}

static int	check_buffer(char *buffer, char *stash, char *line, int iline)
{
	int	ibuff;
	int	max;

	ibuff = 0;
	max = ft_strlen(line) + ft_strlen(buffer) + 1;
	line = malloc(sizeof(char) * max);
	if (line == NULL)
		return (NULL);
	line[max] = '\0';
	while (buffer[ibuff])
	{
		if (buffer[ibuff] == '\n')
		{
			save_stash(buffer, stash, ibuff);
			return (0);
		}
		ibuff++;
	}
	line = ft_strjoin(line, buffer);
	return (1);
}

static int	add_stash(char *stash, char *line)
{
	int	iline;
	int	istash;

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
	static char	*stash[1024];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			isread;
	int			iline;

	iline = 0;
	isread = 1;
	stash[fd] = NULL;
	line = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (stash[fd])
		iline = add_stash(stash, line);
	while (isread)
	{
		isread = read(fd, buffer, BUFFER_SIZE);
		if (isread < 0 || !buffer)
			return (NULL);
		buffer[BUFFER_SIZE + 1] = '\0';
		if (check_buffer(buffer, stash[fd], line, iline) == 0)
			isread = 0;
	}
	return (line);
}
