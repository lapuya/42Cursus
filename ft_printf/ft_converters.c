/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 20:08:50 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/15 11:28:53 by lapuya-p         ###   ########.fr       */
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

char	*ft_convert(long n, int size, char *str)
{
	int		sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	str[size--] = '\0';
	while (size > 0)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	if (sign == -1)
		str[0] = '-';
	else
		str[0] = (n % 10) + '0';
	return (str);
}

int	ft_itoa(int n)
{
	char	*str;
	int		size;
	long	num;
	int		i;

	num = n;
	size = ft_determine_size(num);
	str = malloc(sizeof(char) * (size + 1));
	str = ft_convert(num, size, str);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (size);
}

char	*ft_uconvert(unsigned int n, int size, char *str)
{
	str[size--] = '\0';
	while (size > 0)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	str[0] = (n % 10) + '0';
	return (str);
}

int	ft_uitoa(unsigned int n)
{
	char			*str;
	int				size;
	unsigned int	num;
	int				i;

	num = n;
	size = ft_determine_usize(num);
	str = malloc(sizeof(char) * (size + 1));
	str = ft_uconvert(num, size, str);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (size);
}
