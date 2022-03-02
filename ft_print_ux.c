/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:32:27 by modysseu          #+#    #+#             */
/*   Updated: 2021/11/17 20:45:00 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(unsigned int n)
{
	char	*p;

	p = "0123456789ABCDEF";
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

int	ft_print_ux(va_list	ap)
{
	unsigned int	n;
	int				size_nbr;

	size_nbr = 0;
	n = va_arg(ap, unsigned int);
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
