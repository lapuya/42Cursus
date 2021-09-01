/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:36:34 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/16 11:33:28 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*aux_list;

	aux_list = (t_list *)malloc(sizeof(t_list));
	if (!aux_list)
		return (NULL);
	aux_list->content = content;
	aux_list->next = NULL;
	return (aux_list);
}
