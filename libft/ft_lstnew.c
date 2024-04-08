/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:45:50 by ochetrit          #+#    #+#             */
/*   Updated: 2023/10/31 12:42:02 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}

/*int main()
{
	t_list *middle;
	t_list *front;
	t_list *back;
	middle = ft_lstnew("c");
	printf("%lu", sizeof(middle));
	front = ft_lstnew("salut");
	back = ft_lstnew("florian");
	printf("%s et %d", (char *)middle->content, ft_lstsize(middle));
	ft_lstadd_front(&middle, front);
	ft_lstadd_back(&front, back);
	printf("\n%s et %d", (char *)front->content, ft_lstsize(front));
	printf("\n%s", (char *)ft_lstlast(front)->content);
	ft_lstclear(front);
}*/
