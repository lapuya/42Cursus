/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:28:41 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/13 08:56:15 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
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
        return (0);
}