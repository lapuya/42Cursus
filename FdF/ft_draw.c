/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 08:56:35 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/09/02 14:54:28 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	ft_set_style(t_map *map, int zoom)
{
	int	z;
	int	z1;

	z = 0;
	printf("%d\n%d\n", map->a.y, map->a.x);
	z = map->matrix[map->a.y][map->a.x];
	z1 = map->matrix[map->b.y][map->b.x];
	if (z)
		map->color = 0xe80c0c;
	else
		map->color = 0xffffff;
	map->a.x *= zoom;
	map->a.y *= zoom;
	map->b.x *= zoom;
	map->b.y *= zoom;
}*/

void	ft_bresenham_algorithm(t_fdf *fdf)
{
	int	x_delta;
	int	y_delta;
	int	x;
	int	y;
	int	p;

	//ft_set_style(fdf->map, fdf->map->zoom);
	x_delta = fdf->map->b.x - fdf->map->a.x;
	y_delta = fdf->map->b.y - fdf->map->a.y;
	x = fdf->map->a.x;
	y = fdf->map->a.y;
	p = 2*y_delta-x_delta;
	while (x < fdf->map->b.x)
	{
		if (p>=0)
		{
			mlx_pixel_put(fdf->mlx_pointer, fdf->window, x, y, fdf->map->color);
			y++;
			p = p + 2*y_delta-2*x_delta;
		}
		else
		{
			mlx_pixel_put(fdf->mlx_pointer, fdf->window, x, y, 0xffffff);
			p = p + 2*y_delta;
		}
		x++;
	}				
}

void	ft_set_coords(t_coords *coord, int x, int y)
{
	coord->x = x;
	coord->y = y;
}

void	ft_draw(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			ft_set_coords(&fdf->map->a, x, y);
			if (x < (fdf->map->width - 1))
			{
				ft_set_coords(&fdf->map->b, x + 1, y);
				ft_bresenham_algorithm(fdf);
			}
			if (y < (fdf->map->height - 1))
			{
				ft_set_coords(&fdf->map->b, x, y + 1);
				ft_bresenham_algorithm(fdf);
			}
			x++;
		}
		y++;
	}
}
