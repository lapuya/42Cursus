/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:06:28 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/19 13:23:40 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int	main()
{
	int 	fd;
	int		next_line;
	char	*line;
	
	fd = open("example1.txt", O_RDONLY);
	next_line = get_next_line(fd, &line);
	printf("%d\n", next_line);
	printf("%s\n", line);
	
	
	return (0);
}