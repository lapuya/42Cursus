/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:01:35 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/15 14:08:11 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*aux;

	aux = (char *)haystack;
	if (*needle == '\0')
		return (aux);
	i = 0;
	while (aux[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == aux[i + j] && aux[i + j] != '\0' && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return (aux + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
