/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:06:52 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/23 12:54:34 by ren              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_count_and_print(char c, va_list params, t_format *flags)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_char_case(params, flags);
	else if (c == 's')
		count += ft_string_case(params, flags);
	else if (c == 'p')
		count += ft_pointer_case(params, flags);
	else if (c == 'd' || c == 'i')
		count += ft_decimal_integer_case(params, flags);
	else if (c == 'u')
		count += ft_udecimal_case(params, flags);
	else if (c == 'x' || c == 'X')
		count += ft_hexadecimal_case(c, params, flags);
	else
		count += ft_char_case(params, flags);
	return (count);
}

int	ft_print_and_count(const char *str, va_list params)
{
	int			count;
	int			i;
	t_format	flags;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_initialize_flags(&flags);
			i = ft_process_flags(str, i, &flags);
			count += ft_count_and_print(str[i], params, &flags);
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
