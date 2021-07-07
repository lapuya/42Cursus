/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:04:05 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/16 08:58:41 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t				i;
	unsigned char		*p_dst;
	unsigned char		*p_src;

	i = 0;
	p_dst = (unsigned char *) dst;
	p_src = (unsigned char *) src;
	while (i < len)
	{
		p_dst[i] = p_src[i];
		if (p_src[i] == (unsigned char)c)
			return (&p_dst[i + 1]);
		i++;
	}
	return (NULL);
}
