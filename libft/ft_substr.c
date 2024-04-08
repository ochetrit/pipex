/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:41:07 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/08 10:50:04 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) >= len)
		subs = (char *)malloc((len + 1) * sizeof(char));
	else
		subs = (char *)malloc((ft_strlen(s + start) + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
