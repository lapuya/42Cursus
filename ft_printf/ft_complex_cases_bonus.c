/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 11:16:43 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/15 12:36:59 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_case(va_list params)
{
	unsigned long	p;
	int				count;

	count = 0;
	p = va_arg(params, unsigned long);
	write(1, "0x", 2);
	count += ft_long_to_hex(p);
	return (count + 2);
}

int	ft_decimal_integer_case(va_list params)
{
	int	count;
	int	nbr;

	nbr = va_arg(params, int);
	count = ft_itoa_2(nbr);
	return (count);
}

int	ft_udecimal_case(va_list params)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	nbr = va_arg(params, unsigned int);
	count = ft_uitoa(nbr);
	return (count);
}

int	ft_hexadecimal_case(va_list params)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	nbr = va_arg(params, unsigned int);
	count += ft_tohex(nbr);
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