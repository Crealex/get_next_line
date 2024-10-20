/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:50:53 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/20 17:23:34 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	printf("testttttttttt\n");
	int fd;

	fd = open("file1.txt", O_RDONLY);
	if (0 > fd)
		return (1);
	printf("la premiere ligne de mon fichier est : %s\n", get_next_line(fd));
	printf("la deuxieme ligne de mon fichier est : %s\n", get_next_line(fd));
	close(fd);
	return (0);
}
