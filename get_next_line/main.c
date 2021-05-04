/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:06:28 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/05/04 10:42:57 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int	main()
{
	int 	fd;
	int		next_line;
	char	*line;
	
	fd = open("example4.txt", O_RDONLY);
	
	while ((next_line = get_next_line(fd, &line)) != 0)
	{
		printf("%d\n", next_line);
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}