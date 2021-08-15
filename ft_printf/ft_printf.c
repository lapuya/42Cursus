/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:06:52 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/15 12:06:33 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	ft_count_and_print(char c, va_list params)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_char_case(params);
	else if (c == 's')
		count += ft_string_case(params);
	else if (c == 'p')
		count += ft_pointer_case(params);
	else if (c == 'd' || c == 'i')
		count += ft_decimal_integer_case(params);
	else if (c == 'u')
		count += ft_udecimal_case(params);
	else if (c == 'x')
		count += ft_hexadecimal_case(params);
	else if (c == 'X')
		count += ft_upper_hex_case(params);
	else
		count += ft_percentage_case();
	return (count);
}

int	ft_print_and_count(const char *str, va_list params)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_count_and_print(str[i], params);
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	v_list;

	va_start(v_list, format);
	count = ft_print_and_count(format, v_list);
	va_end(v_list);
	return (count);
}
