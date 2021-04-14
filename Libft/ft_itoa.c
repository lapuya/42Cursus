/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:21:03 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/14 12:20:03 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int		ft_determine_size(long n)
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

static char		*ft_convert(long n, int size, char *str)
{
	int		sign;

	sign = 1;
	if(n < 0)
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

	return str;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	long	num;

	num = n;
	size = ft_determine_size(num);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str = ft_convert(num, size, str);
	return (str);
}

/*int		main()
{
	printf("%s", ft_itoa(0));
	return (0);
}*/