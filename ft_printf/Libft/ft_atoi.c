/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:47:22 by ren               #+#    #+#             */
/*   Updated: 2021/08/23 11:47:38 by ren              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
