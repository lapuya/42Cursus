/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliaries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 11:20:28 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/15 12:06:32 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_determine_size(long n)
{
	int		size;

	size = 0;
	if (n == 0)
	{
		size++;
		return (size);
	}
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_determine_usize(unsigned int n)
{
	int		size;

	size = 0;
	if (n == 0)
	{
		size++;
		return (size);
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_long_to_uphex(unsigned long nbr)
{
	char	*base;
	int		count;

	count = 1;
	base = "0123456789ABCDEF;
	if (nbr >= 16)
	{
		count += ft_long_to_hex(nbr / 16);
		ft_putchar(*(base + (nbr % 16)));
	}
	else
		ft_putchar(*(base + nbr));
	return (count);
}
