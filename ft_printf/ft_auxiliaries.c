/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliaries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 11:20:28 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/15 11:28:52 by lapuya-p         ###   ########.fr       */
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
