/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 08:56:35 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/09/06 15:53:10 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_style(t_map *map, t_coords a)
{
	int	z;

	z = map->matrix[a.y][a.x];
	if (z)
		map->color = 0xe80c0c;
	else
		map->color = 0xffffff;
}

/*void	ft_apply_isometry(t_coords *c, int z)
{
	c->x = (c->x - c->y) * cos(0.8);
	c->y = (c->x + c->y) * sin(0.8) - z;	

}*/

void	ft_bresenham_algorithm(t_fdf *fdf, t_coords a, t_coords b)
{
	int	x_delta;
	int	y_delta;
	int	x;
	int	y;
	int	p;
	int	z;
	int	z1;

	z = fdf->map->matrix[a.y][a.x];
	z1 = fdf->map->matrix[b.y][b.x];
	ft_set_style(fdf->map, a);
	//ft_apply_isometry(&a, fdf->map->matrix[a.y][a.x]);
	//ft_apply_isometry(&b, fdf->map->matrix[b.y][b.x]);

	/*a.x = (a.x - a.y) * cos(0.8);
	a.y = (a.x + a.y) * sin(0.8) - z;
	b.x = (b.x - b.y) * cos(0.8);
	b.y = (b.x + b.y) * sin(0.8) - z1;*/
	a.x *= fdf->map->zoom;
	a.y *= fdf->map->zoom;
	b.x *= fdf->map->zoom;
	b.y *= fdf->map->zoom;

	printf("a.x: %d\n", a.x);
	
	x_delta = b.x - a.x;
	y_delta = b.y - a.y;
	x = a.x;
	y = a.y;
	p = 2*y_delta-x_delta;
	printf("y: %d\n", y);
	while (x < b.x || y < b.y)
	{
		printf("entro bucle\n");
		printf("x: %d\n", x);
		printf("b.x: %d\n", b.x);
		printf("y: %d\n", y);
		printf("b.y: %d\n", b.y);
		printf("p: %d\n", p);
		sleep(1);
		if (p>=0)
		{
			mlx_pixel_put(fdf->mlx_pointer, fdf->window, x, y, fdf->map->color);
			y++;
			p = p + 2 * y_delta - 2 * x_delta;
		}
		else
		{
			mlx_pixel_put(fdf->mlx_pointer, fdf->window, x, y, 0xffffff);
			p = p + 2 * y_delta;
			x++;
		}
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
	t_coords	a;
	t_coords	b;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			ft_set_coords(&a, x, y);
			if (x < (fdf->map->width - 1))
			{
				ft_set_coords(&b, x + 1, y);
				ft_bresenham_algorithm(fdf, a, b);
			}
			if (y < (fdf->map->height - 1))
			{
				ft_set_coords(&b, x, y + 1);
				ft_bresenham_algorithm(fdf, a, b);
			}
			x++;
		}
		y++;
	}
}
