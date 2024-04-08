/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:25:24 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/05 17:25:50 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_create_str(int n)
{
	char	*nbr;
	size_t	len;
	size_t	sgn;

	len = 1;
	sgn = 0;
	if (n < 0)
	{
		len++;
		sgn = 1;
	}
	n /= 10;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	nbr = malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr = (char *)ft_memset(nbr, '0', len);
	if (sgn)
		nbr[0] = '-';
	nbr[len] = '\0';
	return (nbr);
}

char	*ft_itoa(int n)
{
	size_t			len;
	char			*nbr;
	unsigned int	pos_nb;

	if (n < 0)
		pos_nb = n * -1;
	else
		pos_nb = n;
	nbr = ft_create_str(n);
	if (!nbr)
		return (NULL);
	len = ft_strlen(nbr) - 1;
	while (len < 12 && nbr[len] != '-')
	{
		nbr[len] = pos_nb % 10 + '0';
		pos_nb /= 10;
		len--;
	}
	return (nbr);
}
