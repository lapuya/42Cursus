/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:02:47 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/18 09:16:11 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_allocmem(char const *s, char c)
{
	int		count;

	if (!s)
		return (NULL);
	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			count++;
		}
		else
			s++;
	}
	return (malloc((count + 1) * sizeof(char *)));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**result;

	result = ft_allocmem(s, c);
	if (!result)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] != c && s[i])
				i++;
			result[k] = ft_substr(s, j, i - j);
			k++;
		}
		if (s[i] != '\0')
			i++;
	}
	result[k] = NULL;
	return (result);
}
