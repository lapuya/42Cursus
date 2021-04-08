/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:48:45 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/08 16:56:53 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cont_dest;
	size_t	cont_src;
	size_t	j;
	size_t	i;

	cont_dest = ft_strlen(dst);
	cont_src = ft_strlen(src);
	i = 0;
	j = cont_dest;
	if (dstsize == 0)
		return (cont_src);
	if (dstsize < cont_len)
		return (cont_src + dstsize);
	else
	{
		while (src[i] != '\0' && (cont_dest + i) < dstsize)
			dst[j++] = src[i++];
		if ((cont_dest + i) == dstsize)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (cont_dest + cont_src);
	}
}
