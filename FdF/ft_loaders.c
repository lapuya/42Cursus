/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loaders.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:46:18 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/09/06 14:18:32 by lapuya-p         ###   ########.fr       */
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

void	ft_load_matrix(int *matrix_nums, char *line)
{
	char	**nbrs;
	int	i;

	nbrs = ft_split(line, ' ');
	matrix_nums[0] = 1;
	i = 0;
	while (nbrs[i])
	{
		matrix_nums[i] = ft_atoi(nbrs[i]);
		free(nbrs[i]);
		i++;
	}
	free(nbrs);
	printf("\n");
}

void	ft_load_map(const char *file, t_map *map)
{
	int	i;
	int	fd;
	char	*line;

	map->height = ft_getheight(file);
	map->width = ft_get_width(file);
	map->matrix = (int **)malloc(sizeof(int*) * (map->height + 1));
	i = 0;
	while(i <= map->height)
	{
		map->matrix[i] = (int*)malloc(sizeof(int) * (map->width + 1));
		i++;
	}
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		ft_load_matrix(map->matrix[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}

void	ft_load_fdf(const char *file, t_fdf *fdf)
{
	fdf->map = (t_map *)malloc(sizeof(t_map));
	ft_load_map(file, fdf->map);
	fdf->map->zoom = 20;
	fdf->map->color = 0;
	fdf->mlx_pointer = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx_pointer, 1000, 1000, "FdF");
}


