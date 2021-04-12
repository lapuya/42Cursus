/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:48:45 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/12 13:37:38 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t  i;
    size_t  slen;

    i = 0;
    slen = ft_strlen(src);
    while (*dst && dstsize > 0)
    {
        dst++;
        i++;
        dstsize--;
    }
    while (*src && dstsize-- > 1)
        *dst++ = *src++;
    if (dstsize == 1 || *src == 0)
        *dst = '\0';
    return (slen + i);
}
