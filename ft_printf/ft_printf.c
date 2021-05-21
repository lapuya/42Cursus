/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 08:30:30 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/05/21 13:05:57 by lapuya-p         ###   ########.fr       */
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

void	ft_print_type(int c, va_list params)
{
	char caracter;

	caracter = va_arg(params, int);
	if (c == 'c')
		ft_putchar(caracter);
}

int	ft_determine_case_and_print(t_format *style, va_list params)
{
	int count;
	int has_flags;

	count = 0;
	while (style->has_flags == 1)
		style->has_flags = ft_processflags(&style->flags);
	ft_print_type(style->type, params);
	return (count);
}


int	ft_print_and_count(const char *format, va_list params)
{
	int			i;
	int			count;
	char		c;
	t_format	style;

	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_initialize_format(&style);
			ft_parse_format(&style, format, i);
			count += ft_determine_case_and_print(&style, params);
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
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

