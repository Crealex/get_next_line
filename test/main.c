/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:50:53 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/21 16:56:37 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd1;
	int fd2;
	int i;

	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	i = 1;
	if (fd1 < 0)
		return (1);
	printf("\033[0;31m----------FILES1----------\n");
	while (i < 14)
	{
		printf("\033[0;31mligne %d : \033[0m%s\n", i, get_next_line(fd1));
		i++;
	}
	if (fd2 < 0)
		return(1);
	i = 1;
	printf("\033[0;33m----------FILE2----------\n");
	while(i < 23)
	{
		printf("\033[0;33mlinge %d : \033[0m%s\n", i, get_next_line(fd2));
		i++;
	}
	close(fd1);
	close(fd2);
	return (0);
}
