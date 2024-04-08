/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:21:19 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/06 08:21:35 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int character)
{
	while (*str && *str != (unsigned char)character)
		str++;
	if (*str == (unsigned char)character)
		return ((char *)str);
	return (NULL);
}
