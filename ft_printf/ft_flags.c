/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 09:56:37 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/07/06 12:43:04 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_format(t_format *style, char *format)
{
	int i;
	
	i = 0;
	while (*format && *format != '%')
	{

		if (*format == '-' || *format == '0' || *format == '.'||
				*format == '*')
		{
			ft_setflag(&style->flags, *format);
			style->has_flags = 1;
		}
		else if (*format == 'c' || *format == 's' ||
				*format == 'p' || *format == 'd' ||
				*format == 'i' || *format == 'u' ||
				*format == 'x' || *format == 'X')
		{
			style->type = *format;
		}
		format++;
		i++;
	}
	return (i);
}

void	ft_setflag(t_flags *f, char c)
{
	if (c == '-')
		f->minus = 1;
	else if (c == '0')
		f->zero = 1;
	else if (c == '.' || c == '*')
		f->precision = 1;
	f->counter++;
}

void	ft_initialize_format(t_format *f)
{
	ft_initialize_flags(&f->flags);
	f->has_flags = 0;
	f->type = 0;
}

void	ft_initialize_flags(t_flags *f)
{
	f->minus = 0;
	f->zero = 0;
	f->precision = 0;
	f->width = 0;
	f->counter = 0;
}

int	ft_processflags(t_flags *flag, const char *format, int *count)
{
	if (flag->minus == 1)
	{
		printf("%s\n", "ejecutar comportamiento del flag '-'");
		flag->minus = 0;
		flag->counter--;
	}
	else if (flag->zero == 1)
	{
		printf("%s\n", "ejecutar comportamiento del flag zero");
		flag->zero = 0;
		flag->counter--;
	}
	else if (flag->precision == 1)
	{
		if (*format == '.')
		{
			format++;
			while (ft_isdigit(*format))
			{
				flag->width = (flag->width * 10) + (*format - '0');
				format++;
			}
		}
		else if (*format == '*')
		{

		}
		flag->counter--;
	} 

	return (flag->counter);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


