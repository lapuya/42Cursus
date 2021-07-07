/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:22:52 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/07/07 13:43:50 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_initialize_flags(t_flags *f)
{
	f->minus = 0;
	f->zero = 0;
	f->dot = 0;
	f->asterisk = 0;
	f->precision = 0;
	f->width = 0;
}

void	ft_initialize_format(t_format *f)
{
	ft_initialize_flags(&f->flags);
	f->has_flags = 0;
	f->type = 0;
}


