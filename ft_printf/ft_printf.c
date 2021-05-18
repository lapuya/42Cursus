/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 08:30:30 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/05/18 14:05:20 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}


void	ft_initialize_format(t_format f)
{
	f.type = 0;
	f.minus = 0;
	f.zero = 0;
	f.dot = 0;
	f.asterisk = 0;
}

void	ft_parse_format(t_format *style, const char *format)
{
	int i;

	i = 0;
	while (format[i] && format[i] != '%')
	{
		if (format[i] == '-')
			style->minus = 1;
		else if (format[i] == '0')
			style->zero = 1;
		else if (format[i] == '.')
			style->dot = 1;
		else if (format[i] == '*')
			style->dot = 1;
		else if (format[i] == 'c' || format[i] == 's' ||
				format[i] == 'p' || format[i] == 'd' ||
				format[i] == 'i' || format[i] == 'u' ||
				format[i] == 'x' || format[i] == 'X')
			style->type = format[i];
		i++;
	}
}

int	ft_char_case(va_list params)
{
	char c;

	c = va_arg(params, int);
	ft_putchar(c);
	return (1);
}


int	ft_determine_case_and_print(t_format style, va_list params)
{
	int count;

	count = 0;
	if (style.type == 'c')
	{
		count += ft_char_case(params);
	}
	return (count);
}
int	ft_print_and_count(const char *format, va_list params)
{
	int			i;
	int			count;
	t_format	style;

	count = 0;
	ft_initialize_format(style);
	while(*format)
	{
		if (*format == '%')
		{
			format++;
			ft_parse_format(&style, format);
			count += ft_determine_case_and_print(style, params);
		}
		format++;
	}
	return (count);

}


int	ft_printf(const char *format, ...)
{
	int count;
	va_list v_list;
	char *str;
	int num;

	
	va_start(v_list, format);
	count = ft_print_and_count(format, v_list);
/*	str = va_arg(v_list, char *);
	printf("%s\n%s\n", format, str);
	num = va_arg(v_list, int);
	printf("%d\n", num);*/
	va_end(v_list);
	return (count);
}

		/*if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = va_arg(params, int);
			ft_putchar(c);
			count++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			str = va_arg(params, char *);
			count += ft_strlen(str);
			ft_putstr(str);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'p')
		{
			p = va_arg(params, void *);
			count += ft_putptr(p);
			i++;
		}	*/