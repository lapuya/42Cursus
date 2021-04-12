/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:24:01 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/12 09:48:07 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  The strrchr() function is identical to strchr(), 
** except it locates the last occurrence of c.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			ptr = ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		ptr = ((char *)&s[i]);
	return (ptr);
}
