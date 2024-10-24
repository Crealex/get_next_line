/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:23:24 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/24 11:39:27 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(t_list *stash)
{
	int i;
	t_list	*current;

	if(stash == NULL)
		return (0);
	i = 0;
	current = ft_lst_get_last(stash);
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lst_get_last(t_list *stash)
{
	t_list	*current;

	current = stash;
	while (current && current->next)
	{
		current = current->next;
	}
	return (current);
}

void	generate_line(char **line, t_list *stash)
{
	int i;
	int len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len ++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	if (*line == NULL) // peut-etre a mettre dans extract_line
		return ;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	free_stash(t_list *stash)
{
	t_list *current;
	t_list *next;

	current = stash;
	next = stash->next;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}