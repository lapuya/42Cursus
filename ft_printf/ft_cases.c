/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:08:55 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/07/07 14:07:44 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_width(t_flags f, int len)
{
	int count;
	
	count  = 0;
	while (f.width - len > 0)
	{
		ft_putchar(' ');
		f.width--;
		count++;
	}
	return (count);
}


int	ft_char_case(va_list params, t_flags f)
{
	int count;

	count = 0;
	if (f.minus == 0)
	{
		ft_putchar(va_arg(params, int));
		count++;
	}
	else if (f.minus == 1)
	{
		ft_putchar(va_arg(params, int));
		count += ft_process_width(f, 1);
		count++;
	}
	return (count);
}


