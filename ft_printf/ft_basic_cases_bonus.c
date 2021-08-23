/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_cases_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:35:14 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/23 16:54:45 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* Puts the format, where c is -> ' ', '0' and the diff is the result of
 * substracting width - precision */
int	ft_putformat(char c, int diff)
{
	int	count;

	count = 0;
	if (diff <= 0)
		return (count);
	while (count < diff)
	{
		write(1, &c, 1);
		count++;
	}
	return (count);
}

/* Prints the char. If there is no left justification and flag zero is 1,
 * we fill with 0's. If not, with spaces. If there is left justification,
 * we print ' ' */
int	ft_char_case(va_list params, t_format *flags)
{
	char	c;
	int		count;

	count = 1;
	c = va_arg(params, int);
	if (flags->minus == 0)
	{
		if (flags->zeros == 1)
			count += ft_putformat('0', flags->width - 1);
		else
			count += ft_putformat(' ', flags->width - 1);
	}
	write (1, &c, 1);
	if (flags->minus == 1)
		count += ft_putformat(' ', flags->width - 1);
	return (count);
}

/* Prints the string. If there's no precision provided or the precision
 * is larger than the length of the string or there is no dot flag, 
 * the precision is 0. Then we will with '0' or spaces and  if left just.
 * we fill with ' ' */
int	ft_string_case(va_list params, t_format *flags)
{
	int		count;
	char	*str;
	int		len;

	count = 0;
	len = 0;
	str = va_arg(params, char *);
	if (flags->precision < 0 || flags->precision > (int)ft_strlen(str)
		|| flags->dot == 0)
		flags->precision = (int)ft_strlen(str);
	if (flags->minus == 0)
	{
		if (flags->zeros == 1)
			count += ft_putformat('0', flags->width - flags->precision);
		else
			count += ft_putformat(' ', flags->width - flags->precision);
	}
	count += ft_putstr(str, flags->precision);
	if (flags->minus == 1)
		count += ft_putformat(' ', flags->width - flags->precision);
	return (count);
}

/* Prints the special char percentage */
int	ft_percentage_case(void)
{
	write(1, "%", 1);
	return (1);
}
