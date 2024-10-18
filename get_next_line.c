/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:09:41 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/18 11:55:14 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_buffer(char *buffer, static char **stash, char *line, int iline)
{
	int ibuff;
	int istash;
	int max;

	ibuff = 0;
	istash = 0;
	max = ft_strlen(line) + ft_strlen(buff) + 1;
	line = malloc(sizeof(char) * max);
	if (line == NULL)
		return (NULL);
	line[max] = '\0';
	while (buffer[i])
	{
		if (buffer[ibuff] == '\n')
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

int	add_stash(char *stash, char *line)
{
	int iline;
	int istash;

	iline = 0;
	istash = 0;
	while (stash[istash])
	{
		line[iline] = stash[fd][istash];
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
		iline = add_stash(stash, line);
	while (isread) // reflexion en cours car read lit actuellement tout le fichier
	{
		isread = read(fd, buffer, BUFFER_SIZE);
		if (isread < 0 || !buffer)
			return (NULL);
		buffer[BUFFER_SIZE + 1] = '\0';
		check_buffer(buffer, stash, line, iline); // On pourait dire que si cette fonction renvoie 0 alors isread = 0
	}
	return (line);
}
