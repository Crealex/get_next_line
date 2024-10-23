/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:39:34 by alexandre         #+#    #+#             */
/*   Updated: 2024/10/23 22:08:00 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(t_list **stash)
{
	int i;
	return (0);
}

void	read_and_stash(int fd, t_list **stash, int *readed)
{
	char *buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return ;
	//while (!is_newline(*stash) && *readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		buff[*readed] = '\0';
	}
}

char *get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;
	int				isread;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0))
		return (NULL);
	isread = 1;
	line = NULL;
	read_and_stash(fd, &stash, &read);
	return (line);
}