/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:09:02 by ren               #+#    #+#             */
/*   Updated: 2021/08/23 16:45:34 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	ft_itoa_read(int n)
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
