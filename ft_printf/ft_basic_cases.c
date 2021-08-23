/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:35:14 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/23 16:40:59 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Prints the char */
int	ft_char_case(va_list params)
{
	ft_putchar(va_arg(params, int));
	return (1);
}

/* Gets the str and prints */
int	ft_string_case(va_list params)
{
	int		count;
	char	*str;

	count = 0;
	str = va_arg(params, char *);
	while (str[count])
	{
		ft_putchar(str[count]);
		count++;
	}
	return (count);
}

/* Prints the special char '%' */
int	ft_percentage_case(void)
{
	write(1, "%", 1);
	return (1);
}
