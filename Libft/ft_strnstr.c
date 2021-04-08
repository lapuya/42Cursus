/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:28:41 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/08 17:34:12 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	    int i;
        int j;

        if (*needle == '\0')
                return (haystack);
        i = 0;
        while (haystack[i] != '\0' && i < len)
        {
                j = 0;
                while (needle[j] == haystack[i + j])
                {
                        if (needle[j + 1] == '\0')
                                return (haystack + i);
                        j++;
                }
                i++;
        }
        return (0);
}