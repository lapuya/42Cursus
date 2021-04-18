/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 07:58:01 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/16 08:38:30 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strdup() function allocates sufficient memory for a copy 
** of the string s1, does the copy, and returns a pointer to it.  
** The pointer may subsequently be 
** used as an argument to the function free(3).
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1) + 1;
	ptr = malloc(sizeof(char) * len);
	if (!ptr)
		return (0);
	ptr = ft_memcpy(ptr, s1, len);
	return (ptr);
}
