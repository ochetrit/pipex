/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:23:23 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/05 17:24:05 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if ((nmemb * size < nmemb || nmemb * size < size) && size && nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	return (ft_bzero(ptr, size * nmemb));
}

/*int main()
{
	char *s = (char *)ft_calloc(0, 100);
	char *s2 = (char *)calloc(0, 100);
	printf("%s : %s",s, s2);
}*/