/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_cases_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 11:16:43 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/23 17:01:12 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* Prints the pointer. If no left justification and no flag zero, we fill
 * with spaces then we write '0x'. If the flag zero is activated and no
 * left justification we fill with '0' */
int	ft_pointer_case(va_list params, t_format *flags)
{
	size_t	p;
	int		count;
	int		ptr_size;

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

/* If the number is negative we write '-'. We treats the flag and
 * if the flag space is 1 and nbr is positive we print the space.
 * If the flag is plus and is >= 0, then we print '+' */
int	ft_decimal_integer_case(va_list params, t_format *flags)
{
	int		count;
	int		nbr_size;
	int		nbr;

	count = 0;
	nbr = va_arg(params, int);
	if (nbr < 0)
		ft_putminus(flags, &count);
	nbr_size = ft_nbrlen(nbr);
	count += nbr_size;
	if ((flags->precision < 0) || (flags->minus == 0 && flags->zeros == 1))
		flags->precision = flags->width;
	if (nbr_size > flags->precision)
		flags->precision = nbr_size;
	if (flags->minus == 0)
		count += ft_putformat(' ', flags->width - flags->precision);
	count += ft_putformat('0', flags->precision - nbr_size);
	if (flags->space == 1 && nbr >= 0)
		ft_putspace(flags, &count);
	if (flags->plus == 1 && nbr >= 0)
		ft_putplus(flags, &count);
	ft_itoa_read_2(nbr);
	if (flags->minus == 1)
		count += ft_putformat(' ', flags->width - flags->precision);
	return (count);
}

/* Prints unsigned decimal. Process flags and then uitoa */
int	ft_udecimal_case(va_list params, t_format *flags)
{
	unsigned int	nbr;
	int				nbr_size;
	int				count;

	count = 0;
	nbr = va_arg(params, int);
	if (nbr < 0)
	{
		flags->width--;
		count++;
	}
	nbr_size = ft_nbrlen(nbr);
	count += nbr_size;
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

/* printf the hexadecimal case and looks for the sharp flag. This
 * functions treats 'x' and 'X' */
int	ft_hexadecimal_case(char c, va_list params, t_format *flags)
{
	int				count;
	unsigned int	nbr;
	int				size;

	count = 0;
	nbr = va_arg(params, unsigned int);
	size = ft_ptrlen(nbr);
	if ((flags->precision < 0) || (flags->minus == 0 && flags->zeros == 1))
		flags->precision = flags->width;
	if (size > flags->precision)
		flags->precision = size;
	if (flags->minus == 0)
		count += ft_putformat(' ', flags->width - flags->precision);
	count += ft_putformat('0', flags->precision - size);
	if (flags->sharp && nbr)
		ft_put_hexsign(flags, c, &count);
	if (c == 'x')
		count += ft_tohex(nbr);
	else
		count += ft_to_uphex(nbr);
	if (flags->minus == 1)
		count += ft_putformat(' ', flags->width - flags->precision);
	return (count);
}
