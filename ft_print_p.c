/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:27:26 by modysseu          #+#    #+#             */
/*   Updated: 2021/11/17 20:36:16 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(unsigned long n)
{
	char	*p;

	p = "0123456789abcdef";
	if (n > 15)
	{
		ft_putnbr(n / 16);
		ft_putnbr(n % 16);
	}
	else
	{
		write(1, &p[n], 1);
	}
}

int	ft_print_p(va_list	ap)
{
	unsigned long	n;
	int				size_nbr;

	size_nbr = 0;
	n = va_arg(ap, unsigned long);
	size_nbr += write(1, "0x", 2);
	ft_putnbr(n);
	if (n == 0)
		size_nbr++;
	while (n)
	{
		size_nbr++;
		n /= 16;
	}
	return (size_nbr);
}
