/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:28:41 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/12 13:59:47 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
/* char *p = (char *) haystack, *pEnd = (char *)haystack+len;
        size_t j = 0;
        size_t i = 0;
        size_t substr_len = ft_strlen(needle);
        if (*needle == '\0')
                return p;
         if(0 == substr_len)
                return p; // the empty string is contained everywhere.

         pEnd -= (substr_len - 1);
        while (p[i] != '\0' && i < len)
        {
                j = 0;
                while (needle[j] == p[i + j])
                {
                        if (needle[j + 1] == '\0')
                                return (p + i);
                        if(0 == ft_strncmp(p, needle, substr_len))
                                 return p;
                        j++;

                }
                i++;
        }
         return NULL;*/
	/*size_t i;
        int j;
        char *aux;

        aux = (char *)haystack;
        if (*needle == '\0')
                return (aux);
        i = 0;
        while (aux[i] != '\0' && i < len)
        {
                j = 0;
                while (needle[j] == aux[i + j])
                {
                        if (needle[j + 1] == '\0')
                                return (aux + i);
                        j++;
                }
                i++;
        }
        return (0);*/
}