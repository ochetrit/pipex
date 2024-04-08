/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:23:28 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/06 08:24:04 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if ((!s1 || !s2) && !n)
		return (NULL);
	if (!*s2)
		return ((char *)s1);
	while (*s1 && n)
	{
		i = 0;
		while (s1[i] == s2[i] && s2[i] && i < n)
			i++;
		if (!s2[i])
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
