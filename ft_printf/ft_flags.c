/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 09:56:37 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/05/21 13:05:49 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_format(t_format *style, const char *format, int i)
{
	while (format[i] && format[i] != '%')
	{

		if (format[i] == '-' || format[i] == '0' || format[i] == '.'||
				format[i] == '*')
		{
			ft_setflag(&style->flags, format[i]);
			style->has_flags = 1;
		}
		else if (format[i] == 'c' || format[i] == 's' ||
				format[i] == 'p' || format[i] == 'd' ||
				format[i] == 'i' || format[i] == 'u' ||
				format[i] == 'x' || format[i] == 'X')
		{
			style->type = format[i];
		}
		i++;
	}
}

void	ft_setflag(t_flags *f, char c)
{
	if (c == '-')
		f->minus = 1;
	else if (c == '0')
		f->zero = 1;
	else if (c == '.')
		f->dot = 1;
	else if (c == '*')
		f->asterisk = 1;
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
	f->dot = 0;
	f->asterisk = 0;
	f->counter = 0;
}

int	ft_processflags(t_flags *flag)
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
	else if (flag->dot == 1)
	{
		printf("%s\n", "ejecutar flag '.'");
		flag->dot = 0;
		flag->counter--;
	} 
	else if (flag->asterisk == 1)
	{
		printf("%s\n", "ejecutar flag '*'");
		flag->asterisk = 0;
		flag->counter--;
	}

	return (flag->counter);
}


