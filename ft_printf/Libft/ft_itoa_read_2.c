/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_read_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:12:23 by ren               #+#    #+#             */
/*   Updated: 2021/08/23 11:16:42 by ren              ###   ########.fr       */
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
	int	sign;

	sign = 1;
	if (n < 0)
	{
		size--;
		n = -n;
		sign = -1;
	}
	str[size--] = '\0';
	while (size > 0)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	str[0] = (n % 10) + '0';
	return (str);}

int	ft_itoa_read_2(long n)
{
	char	*str;
	int		i;
	int 	size;

	size = ft_determine_size(n);
	str = malloc(sizeof(char) * (size + 1));
	str = ft_convert(n, size, str);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (size);
}
