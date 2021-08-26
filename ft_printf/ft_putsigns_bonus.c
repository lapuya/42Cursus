/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsigns_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:51:50 by ren               #+#    #+#             */
/*   Updated: 2021/08/23 17:13:23 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putminus(t_format *f, int *count)
{
	write(1, "-", 1);
	f->width--;
	*count = *count + 1;
}

void	ft_putplus(t_format *f, int *count)
{
	write (1, "+", 1);
	f->width--;
	*count = *count + 1;
}

void	ft_putspace(t_format *f, int *count)
{
	write (1, " ", 1);
	f->width--;
	*count = *count + 1;
}

void	ft_put_hexsign(t_format *f, char c, int *count)
{
	if (c == 'x')
		write(1, "0x", 2);
	else if (c == 'X')
		write(1, "0X", 2);
	f->width--;
	*count = *count + 2;
}
