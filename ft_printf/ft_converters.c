/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 20:08:50 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/23 10:31:11 by ren              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_long_to_hex(unsigned long nbr)
{
	char	*base;
	int		count;

	count = 1;
	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		count += ft_long_to_hex(nbr / 16);
		ft_putchar(*(base + (nbr % 16)));
	}
	else
		ft_putchar(*(base + nbr));
	return (count);
}

int	ft_to_uphex(unsigned int nbr)
{
	char	*base;
	int		count;

	count = 1;
	base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		count += ft_to_uphex(nbr / 16);
		ft_putchar(*(base + (nbr % 16)));
	}
	else
		ft_putchar(*(base + nbr));
	return (count);
}

int	ft_tohex(unsigned int nbr)
{
	char	*base;
	int		count;

	count = 1;
	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		count += ft_tohex(nbr / 16);
		ft_putchar(*(base + (nbr % 16)));
	}
	else
		ft_putchar(*(base + nbr));
	return (count);
}
