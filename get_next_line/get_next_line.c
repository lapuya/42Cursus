/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:02:40 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/19 14:17:35 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int		ret;
	char	buf[BUFFER_SIZE + 1];
	char	*aux[4096];
	int		len;
	
	len = 0;
	if (!fd)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
			if (ret == -1)
				return (-1);
			buf[ret] = '\0';
			len = ft_strlen(buf);
			printf("buf es: %s\n ", buf);
			printf("aux es: %s\n ", aux[fd]);
	}

	
	

	return (1);
	
		
	
	
}