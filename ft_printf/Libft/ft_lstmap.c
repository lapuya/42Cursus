/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 09:37:03 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/16 12:38:58 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	aux = ft_lstnew((f(lst->content)));
	if (!aux)
		return (NULL);
	tmp = aux;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew((f(lst->content)));
		if (!tmp)
		{
			ft_lstclear(&aux, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (aux);
}
