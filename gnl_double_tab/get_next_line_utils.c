/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:10:04 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/23 21:28:58 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i1;
	int		i2;
	char	*res;

	i1 = 0;
	i2 = 0;
	if (s1 != NULL)
		res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	else
		res = malloc(sizeof(char) * (ft_strlen(s2) + 2));
	if (res == NULL)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	while (s1 && ft_strlen(s1) > 0 && s1[i1])
	{
		res[i1] = s1[i1];
		i1++;
	}
	while (s2[i2] && s2[i2] != '\n')
	{
		res[i1] = s2[i2];
		i1++;
		i2++;
		//printf("test\n");
	}
	if (s2[i2] == '\n')
	{
		res[i1] = s2[i2];
		i1++;
		//printf("test\n");
	}
	res[i1] = '\0';
	free(s1);
	return (res);
}

int	real_len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
