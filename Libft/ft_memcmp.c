/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:16:12 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/12 09:19:14 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t							i;
	const unsigned char			*p_s1;
	const unsigned char			*p_s2;

	i = 0;
	p_s1 = s1;
	p_s2 = s2;
	while (i < n && p_s1[i] == p_s2[i])
		i++;
	if (i == n)
		return (0);
	else
		return (p_s1[i] - p_s2[i]);
}
