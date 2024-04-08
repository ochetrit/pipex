/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:19:02 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/05 17:22:55 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;

	dest = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest = (char *)ft_memcpy(dest, s, ft_strlen(s) + 1);
	return (dest);
}
