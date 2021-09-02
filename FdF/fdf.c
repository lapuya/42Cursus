/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:36:07 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/09/02 14:00:43 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_map *map)
{
	int	i;

	i = 0;
	while(i <= map->height)
	{
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
	free(map);
}

void	ft_free_fdf(t_fdf *fdf)
{
	free_matrix(fdf->map);
	free(fdf);
}

void	ft_show_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while(i < map->height)
	{
		j = 0;
		while(j < map->width)
		{
			printf("%3d", map->matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

}

int	deal_key(int key)
{
	printf("%d", key);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		write(1, "Error. Usage: ./fdf map.fdf", 27);
	fdf = (t_fdf*) malloc(sizeof(t_fdf));

	ft_load_fdf(argv[1], fdf);
	ft_draw(fdf);
	mlx_key_hook(fdf->window, deal_key, NULL);
	mlx_loop(fdf->mlx_pointer);
	//ft_show_map(fdf->map);
	system("leaks fdf");
	return (0);
}
