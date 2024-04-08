/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 07:41:05 by ochetrit          #+#    #+#             */
/*   Updated: 2023/11/10 10:01:27 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	char	d;

	d = (char)c;
	return (write(1, &d, 1));
}

int	ft_putstr(const char *format)
{
	int	n_oct;

	n_oct = 0;
	if (!format)
		return (write(1, "(null)", 6));
	while (*format)
	{
		write(1, format, 1);
		format++;
		n_oct++;
	}
	return (n_oct);
}

int	ft_putnbr(int nb)
{
	int				len;
	unsigned int	nbr;

	len = 0;
	nbr = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		nbr = -nb;
		len++;
	}
	if (nbr > 9)
		len += ft_putnbr(nbr / 10);
	return (len + write(1, &"0123456789"[nbr % 10], 1));
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
		len += ft_putnbr(nb / 10);
	len += write(1, &"0123456789"[nb % 10], 1);
	return (len);
}

int	ft_puthex(unsigned long nb, char key, char ptr)
{
	int	len;

	len = 0;
	if (ptr == 'Y')
	{
		if (nb == 0)
			return (write(1, "(nil)", 5));
		len += write(1, "0x", 2);
	}
	if (nb > 15)
		len += ft_puthex(nb / 16, key, 'n');
	if (key == 'x')
		return (len + write(1, &"0123456789abcdef"[nb % 16], 1));
	return (len + write(1, &"0123456789ABCDEF"[nb % 16], 1));
}
