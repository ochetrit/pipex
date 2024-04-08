/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:41:07 by ochetrit          #+#    #+#             */
/*   Updated: 2024/03/25 11:43:59 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenjoin(char const *s1, char const *s2)
{
	unsigned int	len;

	if (!s1)
		len = 0;
	else
		len = ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2, char c)
{
	char			*str;
	unsigned int	i;

	str = (char *)malloc((ft_lenjoin(s1, s2) + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && *s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	str[i] = c;
	i++;
	while (s2 && *s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}
