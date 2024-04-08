/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:22:10 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/06 08:22:33 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	const char	*ptr;

	ptr = str;
	while (*str)
		str++;
	while (str > ptr && *str != (unsigned char)character)
		str--;
	if (*str == (unsigned char)character)
		return ((char *)str);
	return (NULL);
}
