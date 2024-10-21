/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:09:41 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/21 17:43:57 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*delete_part_of_stash(char *stash)
{
	int i;
	int j;
	char *temp;

	i = 0;
	j = 0;
	temp = malloc(sizeof(char) * (real_len(stash) + 1));
	while (stash[i])
	{
		temp[i] = stash[i];
		i++;
	}
	i = 0;
	while(temp[j] != '\n')
		j++;
	j++;
	while(temp[j] && stash[i])
	{
		stash[i] = temp[j];
		i++;
		j++;
	}
	stash[i] = '\0';
	return (stash);
}

static char	*save_stash(char *buffer, char *stash, int ibuff)
{
	int	istash;

	istash = 0;
	stash = NULL;
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
			return (line);
		}
		ibuff++;
	}
	line = ft_strjoin(line, buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			isread;

	printf("\033[0;32mSTASH debut de fonction: %s\n", stash[fd]);
	isread = 1;
	line = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (stash[fd])
		line = ft_strjoin(line, stash[fd]);
	if (line && line[ft_strlen(line)] == '\n')
	{
		stash[fd] = delete_part_of_stash(stash[fd]);
		return (line);
	}
	while (isread)
	{
		isread = read(fd, buffer, BUFFER_SIZE);
		if (isread < 0 || !*buffer)
			return (NULL);
		buffer[isread] = '\0';
		line = check_buffer(buffer, line);
		if (isread < BUFFER_SIZE || ft_strlen(buffer) < BUFFER_SIZE)
		{
			isread = 0;
			stash[fd] = save_stash(buffer, stash[fd], ft_strlen(buffer));
		}
	}
	printf("\033[0;32mSTASH fin de fonction: %s\n", stash[fd]);
	return (line);
}
