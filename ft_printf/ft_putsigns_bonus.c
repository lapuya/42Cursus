/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsigns_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:51:50 by ren               #+#    #+#             */
/*   Updated: 2021/08/23 14:24:56 by ren              ###   ########.fr       */
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
