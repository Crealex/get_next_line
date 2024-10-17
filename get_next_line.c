/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:09:41 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/17 17:13:51 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_buffer(char *buffer, static char **stash, char *line, int iline)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			while (buffer[i])
				{
					stash[fd][i] = buffer[i];
					i++;
				}
		}
		line[i] = buffer[i];
		i++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char **stash;
	char buffer[BUFFER_SIZE + 1];
	char *line;
	int isread;
	int iline;

	iline = 0;
	isread = 1;
	while (isread)
	{
		isread = read(fd, buffer, BUFFER_SIZE);
		if (!isread || !buffer)
			return (-1);
		check_buffer(buffer, stash, line, iline);



	}



}
