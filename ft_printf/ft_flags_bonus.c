/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:06:23 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/23 12:52:38 by ren              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_initialize_flags(t_format *f)
{
	f->minus = 0;
	f->zeros = 0;
	f->dot = 0;
	f->precision = 0;
	f->width = 0;
	f->sharp = 0;
	f->space = 0;
	f->plus = 0;
}

int	ft_isflag(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'u'
		|| c == 'd' || c == 'i' || c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
}

int	ft_treat_dot(const char *str, t_format *f, int i)
{
	int	pos;

	f->dot = 1;
	pos = i + 1;
	if (ft_isdigit(str[pos]))
	{
		f->precision = ft_atoi(&str[pos]);
		while (ft_isdigit(str[pos]))
			pos++;
		pos--;
	}
	else
	{
		f->precision = 0;
		pos--;
	}
	return (pos);
}

void	ft_treat_marks(t_format *f, char c)
{
	if (c == '#')
		f->sharp = 1;
	else if (c == ' ')
		f->space = 1;
	else if (c == '+')
		f->plus = 1;
}

int	ft_process_flags(const char *str, int i, t_format *f)
{
	int	pos;

	pos = i + 1;
	while (ft_isflag(str[pos]))
	{
		if (str[pos] == '-')
			f->minus = 1;
		else if (str[pos] == '0' && f->zeros == 0)
			f->zeros = 1;
		else if (ft_isdigit(str[pos]))
		{
			f->width = ft_atoi(&str[pos]);
			while (ft_isdigit(str[pos]))
				pos++;
			pos--;
		}
		else if (str[pos] == '.')
			pos = ft_treat_dot(str, f, pos);
		else if (str[pos] == '#' || str[pos] == ' '
			|| str[pos] == '+')
			ft_treat_marks(f, str[pos]);
		pos++;
	}
	return (pos);
}
