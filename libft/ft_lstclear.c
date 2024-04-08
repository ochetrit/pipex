/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:41:37 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/05 17:42:04 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*chn;
	t_list	*temp;

	if (!lst || !del)
		return ;
	chn = *lst;
	while (chn)
	{
		temp = chn->next;
		chn->next = NULL;
		ft_lstdelone(chn, *del);
		chn = temp;
	}
	*lst = NULL;
}
