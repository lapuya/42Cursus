/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 07:56:54 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/12 13:28:12 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_calloc allocates enough space for count objects that are size bytes 
** of memory each and returns a pointer to the allocated memory.  
** The allocated memory is filled with bytes of value zero.
** If there's an error, returns NULL
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, count * size);
	return (ptr);
}
