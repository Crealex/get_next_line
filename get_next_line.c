/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:09:41 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/20 17:26:14 by atomasi          ###   ########.fr       */
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

static char	*check_buffer(char *buffer, char *stash, char *line)
{
	int	ibuff;
	int	max;

	ibuff = 0;
	max = ft_strlen(line) + ft_strlen(buffer) + 1;
	while (buffer[ibuff])
	{
		if (buffer[ibuff] == '\n')
		{
			save_stash(buffer, stash, ibuff);
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
	int			iline;

	iline = 0;
	isread = 1;
	stash[fd] = NULL;
	line = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (stash[fd])
		line = add_stash(stash[fd], line);
	while (isread)
	{
		isread = read(fd, buffer, BUFFER_SIZE);
		if (isread < 0 || !*buffer)
			return (NULL);
		buffer[isread] = '\0';
		line = check_buffer(buffer, stash[fd], line);
		if (isread < BUFFER_SIZE || ft_strlen(buffer) < BUFFER_SIZE)
			isread = 0;
	}
	return (line);
}
