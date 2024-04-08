/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:49:48 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/05 17:50:10 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		*(unsigned char *)s = (unsigned char)c;
		i++;
		s++;
	}
	return (ptr);
}
