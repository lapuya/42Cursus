/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loaders.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:46:18 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/09/01 15:40:51 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_getheight(const char *file)
{
	int	height;
	char	*line;
	int	fd = 0;
	printf("%s\n", file);
	height = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

int	ft_get_width(const char *file)
{
	int	width;
	int	fd;
	char	*line;

	width = 0;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	width = ft_split_count(line, ' ');
	free(line);
	return (width);
}


void	ft_load_map(const char *file, t_map *map)
{
	map->height = ft_getheight(file);
	printf("%s\n", file);
	printf("%d\n", map->height);
	map->width = ft_get_width(file);
	printf("%d\n", map->width);
}

void	ft_load_fdf(const char *file, t_fdf *fdf)
{
	fdf->map = (t_map *)malloc(sizeof(t_map));
	ft_load_map(file, fdf->map);
	free(fdf->map);
}
