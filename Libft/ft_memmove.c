/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:22:40 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/14 08:42:05 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memmove() function copies len bytes from string src to string dst.  
** The twostrings may overlap; the copy is always done in a non-destructive manner.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	char	*p_dst;
	char	*p_src;
	
	if (!dst && !src)
		return (NULL);
	i = 0;
	p_dst = (char *)dst;
	p_src = (char *)src;
	if (p_src < p_dst)
	{
		p_src = p_src + len - 1;
		p_dst = p_dst + len - 1;
		while (len > 0)
		{
			*p_dst-- = *p_src--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*p_dst++ = *p_src++;
			len--;
		}
	}
	return (dst);
}
