/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:44:02 by modysseu          #+#    #+#             */
/*   Updated: 2021/11/17 20:36:43 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(unsigned int n)
{
	if (n == 0)
		write(1, "0", 1);
	else
	{
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

int	ft_print_u(va_list	ap)
{
	unsigned int	n;
	int				size_nbr;

	n = va_arg(ap, int);
	ft_putnbr(n);
	size_nbr = 0;
	if (n == 0)
		size_nbr++;
	while (n)
	{
		size_nbr++;
		n /= 10;
	}
	return (size_nbr);
}
