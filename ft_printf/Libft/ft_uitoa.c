/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:19:44 by ren               #+#    #+#             */
/*   Updated: 2021/08/23 10:22:19 by ren              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
