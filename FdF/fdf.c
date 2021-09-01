/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:36:07 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/09/01 20:25:45 by lapuya-p         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		write(1, "Error. Usage: ./fdf map.fdf", 27);
	fdf = (t_fdf*) malloc(sizeof(t_fdf));

	ft_load_fdf(argv[1], fdf);
	ft_free_fdf(fdf);
	system("leaks fdf");
	return (0);
}
