/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:58:11 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/12 09:40:37 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
** copies n bytes from memory area src to memory area dst.  
** If dst and src overlap, behavior is undefined.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	if (dst == NULL && src == NULL)
		return(dst);
	i = 0;
	p_dst = (unsigned char *) dst;
	p_src = (unsigned char *) src;
	while (i < len)
	{
		p_dst[i] = p_src[i];
		i++;
	}
	return (dst);
}
