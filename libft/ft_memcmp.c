/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:50:29 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/05 17:50:44 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*ps1;
	unsigned char		*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (n && *ps1 == *ps2)
	{
		n--;
		ps1++;
		ps2++;
	}
	if (n)
		return (*ps1 - *ps2);
	return (0);
}
