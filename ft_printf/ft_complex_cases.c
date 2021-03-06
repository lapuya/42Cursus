/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 11:16:43 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/23 16:46:06 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Prints the pointer. It will print the first '0x' then it will 
 * convert the number to hexadecimal. It returns count + 2, 
 * where 2 is the count of printing '0x' */
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

/* Calls the itoa function and reads */
int	ft_decimal_integer_case(va_list params)
{
	int	count;
	int	nbr;

	nbr = va_arg(params, int);
	count = ft_itoa_read(nbr);
	return (count);
}

/* Calls the itoa function which is slighty changed to treat an unsigned */
int	ft_udecimal_case(va_list params)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	nbr = va_arg(params, unsigned int);
	count = ft_uitoa(nbr);
	return (count);
}

/* Converts the number to lowercase hexadecimal */
int	ft_hexadecimal_case(va_list params)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	nbr = va_arg(params, unsigned int);
	count += ft_tohex(nbr);
	return (count);
}

/* Converts the number to Uppercase Hexadecimal */
int	ft_upper_hex_case(va_list params)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	nbr = va_arg(params, unsigned int);
	count += ft_to_uphex(nbr);
	return (count);
}
