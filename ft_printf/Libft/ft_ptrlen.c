/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:52:40 by ren               #+#    #+#             */
/*   Updated: 2021/08/23 11:53:01 by ren              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptrlen(size_t nbr)
{
	int	i;

	i = 0;
	while (nbr >= 16)
	{
		nbr /= 16;
		i++;
	}
	return (i + 1);
}