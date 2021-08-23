/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_cases_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 11:16:43 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/23 11:11:21 by ren              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_pointer_case(va_list params, t_format *flags)
{
	size_t				p;
	int				count;
	int				ptr_size;

	count = 0;
	p = va_arg(params, size_t);
	ptr_size = ft_ptrlen(p);
	if (flags->minus == 0 && flags->zeros == 0)
		count += ft_putformat(' ', flags->width - ptr_size);
	write(1, "0x", 2);
	flags->width -= 2;
	if (flags->minus == 0 && flags->zeros == 1)
		count += ft_putformat('0', flags->width - ptr_size);
	count += ft_long_to_hex(p);
	if (flags->minus == 1)
		count += ft_putformat(' ', flags->width - ptr_size);
	return (count + 2);
}

int	ft_decimal_integer_case(va_list params, t_format *flags)
{
	int		count;
	int		nbr_size;
	int		nbr;

	count = 0;
	nbr = va_arg(params, int);
	if (nbr < 0)
	{
		write (1, "-", 1);
		flags->width--;
		count++;
	}
	nbr_size = ft_nbrlen(nbr);
	count += nbr_size;
	//if (flags->precision == 0 && nbr == 0)
	//	return (ft_putformat('0', flags->width));
	if ((flags->precision < 0) || (flags->minus == 0 && flags->zeros == 1))
		flags->precision = flags->width;
	if (nbr_size > flags->precision)
		flags->precision = nbr_size;
	if (flags->minus == 0)
		count += ft_putformat(' ', flags->width - flags->precision);
	count += ft_putformat('0', flags->precision - nbr_size);
	if (flags->space == 1 && nbr >= 0)
	{
		write(1, " ", 1);
		flags->width--;
		count++;
	}
	if (flags->plus == 1 && nbr >= 0)
	{
		write (1, "+", 1);
		flags->width--;
		count++;
	}
	ft_itoa_read_2(nbr);
	if (flags->minus == 1)
		count += ft_putformat(' ', flags->width - flags->precision);
	return (count);
}

int	ft_udecimal_case(va_list params, t_format *flags)
{
	int		count;
	int		nbr_size;
	unsigned int		nbr;

	count = 0;
	nbr = va_arg(params, int);
	if (nbr < 0)
	{
		flags->width--;
		count++;
	}
	nbr_size = ft_nbrlen(nbr);
	count += nbr_size;
	//if (flags->precision == 0 && nbr == 0)
	//	return (ft_putformat('0', flags->width));
	if ((flags->precision < 0) || (flags->minus == 0 && flags->zeros == 1))
		flags->precision = flags->width;
	if (nbr_size > flags->precision)
		flags->precision = nbr_size;
	if (flags->minus == 0)
		count += ft_putformat(' ', flags->width - flags->precision);
	count += ft_putformat('0', flags->precision - nbr_size);
	ft_uitoa(nbr);
	if (flags->minus == 1)
		count += ft_putformat(' ', flags->width - flags->precision);
	return (count);
}

int	ft_hexadecimal_case(char c, va_list params, t_format *flags)
{
	int				count;
	unsigned int	nbr;
	int	size;

	count = 0;
	nbr = va_arg(params, unsigned int);
	size = ft_ptrlen(nbr);
	//if (flags->precision == 0 && nbr == 0)
	//	return (ft_putformat('0', flags->width));
	if ((flags->precision < 0) || (flags->minus == 0 && flags->zeros == 1))
		flags->precision = flags->width;
	if (size > flags->precision)
		flags->precision = size;
	if (flags->minus == 0)
		count += ft_putformat(' ', flags->width - flags->precision);
	count += ft_putformat('0', flags->precision - size);
	if (flags->sharp && nbr)
	{
		if (c == 'x')
			write(1, "0x", 2);
		else
			write (1, "0X", 2);
		flags->width -= 2;
		count += 2;
	}	
	if (c == 'x')
		count+= ft_tohex(nbr);
	else
		count += ft_to_uphex(nbr);
	if (flags->minus == 1)
		count += ft_putformat(' ', flags->width - flags->precision);
	return (count);
}

int	ft_upper_hex_case(va_list params)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	nbr = va_arg(params, unsigned int);
	count += ft_to_uphex(nbr);
	return (count);
}
