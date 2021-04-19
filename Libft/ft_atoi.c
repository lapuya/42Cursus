/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:54:17 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/18 13:58:41 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
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
