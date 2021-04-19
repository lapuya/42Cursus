/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:02:37 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/19 13:32:34 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strdup(const char *s1)
{
        char    *ptr;
        size_t  len;

        len = ft_strlen(s1) + 1;
        ptr = malloc(sizeof(char) * len);
        if (!ptr)
                return (0);
        ptr = ft_memcpy(ptr, s1, len);
        return (ptr);
}

void    *ft_memcpy(void *dst, const void *src, size_t len)
{
        size_t                          i;
        unsigned char           *p_dst;
        unsigned char           *p_src;

        if (dst == NULL && src == NULL)
                return (dst);
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

size_t  ft_strlen(const char *str)
{
        size_t  i;

        i = 0;
        while (*str != '\0')
        {
                str++;
                i++;
        }
        return (i);
}