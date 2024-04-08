/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:51:01 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/05 17:51:19 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	void	*ptr;

	i = 0;
	if (!dest && !src)
		return (NULL);
	ptr = dest;
	while (i < n)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		i++;
		dest++;
		src++;
	}
	return (ptr);
}
