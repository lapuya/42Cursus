/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:18:24 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/07/07 13:44:37 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_set_flag(t_flags *f, char c)
{
	if (c == '-')
	{
		f->minus = 1;
		f->zero = 0;
	}
	else if (c == '0' && f->minus == 0 && f->width == 0)
		f->zero = 1;
	else if (c == '.')
		f->dot = 1;
	else if (c == '*')
		f->asterisk = 1;
}

void	ft_flag_digit(t_flags *f, char c)
{
	if (f->asterisk == 1)
		f->width = 0;
	f->width = (f->width * 10) + (c - '0');

}
