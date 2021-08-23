/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 09:03:20 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/23 16:20:55 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*tmp;

	aux = *lst;
	if (aux)
	{
		while (aux)
		{
			tmp = aux->next;
			ft_lstdelone(aux, del);
			aux = tmp;
		}
	}
	*lst = NULL;
}
