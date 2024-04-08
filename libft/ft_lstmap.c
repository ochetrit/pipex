/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:43:01 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/05 17:43:32 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*stock;
	t_list	*front;

	front = NULL;
	while (lst)
	{
		stock = ft_lstnew(f(lst->content));
		if (!stock)
		{
			ft_lstclear(&front, *del);
			return (NULL);
		}
		ft_lstadd_back(&front, stock);
		lst = lst->next;
	}
	return (front);
}
