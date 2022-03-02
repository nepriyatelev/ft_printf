/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:55:50 by modysseu          #+#    #+#             */
/*   Updated: 2021/11/17 20:36:31 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			write(1, "-", 1);
		}
		if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
		{
			n += 48;
			write(1, &n, 1);
		}
	}
}

int	ft_print_d_i(va_list	ap)
{
	int	n;
	int	size_nbr;

	n = va_arg(ap, int);
	ft_putnbr(n);
	size_nbr = 0;
	if (n <= 0)
		size_nbr++;
	while (n)
	{
		size_nbr++;
		n /= 10;
	}
	return (size_nbr);
}
