/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:39:34 by alexandre         #+#    #+#             */
/*   Updated: 2024/10/24 11:49:17 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (!stash|| !clean_node)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content)  - i) + 1));
	if (clean_node->content == NULL)
		return;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}

void	extract_line(t_list *stash, char **line)
{
	int i;
	int j;

	if (stash == NULL)
		return ;
	j = 0;
	generate_line(line, stash);
	//maybe verifier que line != NULL
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	add_to_stash(t_list **stash, char *buffer, int readed)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buffer[i] && i < readed)
	{
		new_node->content[i] = buffer[i];
		i++;
	}
	new_node->content[i] = '\0';
		if (*stash == NULL)
		{
			*stash = new_node;
			return ;
		}
	last = ft_lst_get_last(*stash);
	last->next = new_node;
}

void	read_and_stash(int fd, t_list **stash, int *readed)
{
	char *buffer;


	while (!is_newline(*stash) && *readed != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		*readed = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*stash == NULL & *readed == 0) || *readed == -1)
		{
			free(buffer);
			return ;
		}
		buffer[*readed] = '\0';
		add_to_stash(stash, buffer, *readed);
		free(buffer);
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
	read_and_stash(fd, &stash, &isread);
	if (stash == NULL)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}