/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:24:32 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/05 17:24:50 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		nbr;
	char	neg;

	nbr = 0;
	neg = 1;
	while (*nptr == ' ' || (*nptr < 14 && *nptr > 7))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	while (*nptr <= '9' && *nptr >= '0')
	{
		nbr = 10 * nbr + *nptr - '0';
		nptr++;
	}
	return (neg * nbr);
}
