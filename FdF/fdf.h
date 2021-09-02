/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:28:05 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/09/02 14:14:44 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFFER_SIZE 42

# include "Libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include "minilibx_macos/mlx.h"

typedef struct {
	int	x;
	int	y;
}	t_coords;

typedef struct {
	int	height;
	int	width;
	int	**matrix;
	t_coords	a;
	t_coords	b;
	int	zoom;
	int	color;
}	t_map;

typedef struct {
	t_map	*map;
	void	*mlx_pointer;
	void	*window;
}	t_fdf;	

void	ft_load_fdf(const char *file, t_fdf *fdf);
int	get_next_line(int fd, char **line);
void	ft_draw(t_fdf *fdf);
void	ft_free_fdf(t_fdf *fdf);

#endif
