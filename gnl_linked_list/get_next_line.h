/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:31:45 by alexandre         #+#    #+#             */
/*   Updated: 2024/10/24 11:44:23 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //test et debug

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;


char	*get_next_line(int fd);
int		is_newline(t_list *stash);
t_list	*ft_lst_get_last(t_list *stash);
void	generate_line(char **line, t_list *stash);
int	ft_strlen(char *str);
void	free_stash(t_list *stash);

#endif