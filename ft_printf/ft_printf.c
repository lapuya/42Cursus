/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:17:28 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/07/07 14:00:35 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_format(t_format *format, const char * str)
{
	while (*str && !ft_is_flag(*str) && !ft_is_type(*str))
	{
		if (ft_is_flag(*str))
		{
			ft_set_flag(&format->flags, *str);
			format->has_flags = 1;
		}
		else if (ft_isdigit(*str))
			ft_flag_digit(&format->flags, *str);
		else if (ft_is_type(*str))
			format->type = *str;
		str++;
	}
}

int		ft_print_case(t_format format, va_list params)
{
	int count;

	count  = 0;
	if (format.type == 'c')
		count += ft_char_case(params, format.flags);
	return (count);
}



int ft_print_and_count(const char *str, va_list params)
{
	t_format	format;
	int			count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_initialize_format(&format);
			ft_parse_format(&format, str);
			count += ft_print_case(format, params);
		}
		else
		{
			ft_putchar(*str);
			count++;
		}
		str++;
	}
	return (count);
}

int ft_printf(const char *format, ...)
{
	int count;
	va_list v_list;

	va_start(v_list, format);
	count = ft_print_and_count(format, v_list);
	va_end(v_list);
	return (count);
}




