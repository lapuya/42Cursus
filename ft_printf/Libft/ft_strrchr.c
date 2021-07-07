/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:24:01 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/18 09:15:07 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  The strrchr() function is identical to strchr(), 
** except it locates the last occurrence of c.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = ft_strlen(s);
	while (size >= 0)
	{
		if (s[size] == (char)c)
			return ((char *)(s + size));
		size--;
	}
	return (NULL);
}
