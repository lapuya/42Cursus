/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 08:30:30 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/07/06 12:43:02 by lapuya-p         ###   ########.fr       */
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

void	ft_print_type(int c, t_flags *flag, va_list params)
{
	char caracter;
	char *string;
	int y;

	if (c == 'c')
	{
		caracter = va_arg(params, int);
		ft_putchar(caracter);
	}
	else if (c == 's')
	{
		string = va_arg(params, char*);
		if (flag->precision == 1)
		{
			y = 0;
			while (flag->width-- > 0)
				ft_putchar(string[y++]);
			flag->precision = 0;
		}
		else
			ft_putstr(string);
	}

}

int	ft_determine_case_and_print(t_format *style, va_list params, const char *format)
{
	int count;
	int has_flags;

	count = 0;
	while (style->has_flags == 1)
		style->has_flags = ft_processflags(&style->flags, format, &count);
	ft_print_type(style->type, &style->flags, params);
	return (count);
}


int	ft_print_and_count(const char *format, va_list params)
{
	int			count;
	int			move;
	char		c;
	t_format	style;

	count = 0;
	while (*format)
	{
		move = 0;
		if (*format == '%')
		{
			format++;
			ft_initialize_format(&style);
			move = ft_parse_format(&style, (char *)format);
			count += ft_determine_case_and_print(&style, params, format);
			while (move-- > 1)
				format++;
		}
		else
		{
			ft_putchar(*format);
			count++;
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

