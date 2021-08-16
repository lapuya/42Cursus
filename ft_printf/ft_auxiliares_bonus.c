/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliares_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:41:20 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/16 19:23:41 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c != '\0' && (c == 32 || c == '\t' || c == '\v'
			|| c == '\n' || c == '\r' || c == '\f'))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int					i;
	long long unsigned	nbr;
	int					sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 0)
		i++;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr > 9223372036854775807 && sign == 1)
			return (-1);
		if (nbr + 1 > 9223372036854775807 && sign == -1)
			return (0);
		i++;
	}
	return (nbr * sign);
}

int	ft_putstr(char *s, int len)
{
	/*int	i;

	i = 0;
	while (i < len)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);*/
	return (write(1, s, len));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}
