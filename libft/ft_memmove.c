/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:51:33 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/05 17:51:45 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	src += n - 1;
	dest += n - 1;
	while (i < n)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		i++;
		dest--;
		src--;
	}
	return (++dest);
}
