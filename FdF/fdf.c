/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:36:07 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/09/01 15:04:50 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		write(1, "Error. Usage: ./fdf map.fdf", 27);
	fdf = (t_fdf*) malloc(sizeof(t_fdf));

	ft_load_fdf(argv[1], fdf);
	free(fdf);
	system("leaks fdf");
	return (0);
}
