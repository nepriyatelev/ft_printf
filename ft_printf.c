/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:37:45 by modysseu          #+#    #+#             */
/*   Updated: 2021/11/17 21:00:05 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversions(char fmt, va_list	ap)
{
	int		res;

	res = 0;
	if (fmt == 'c')
		res = ft_print_c(ap);
	if (fmt == 's')
		res = ft_print_s(ap);
	if (fmt == 'd')
		res = ft_print_d_i(ap);
	if (fmt == 'i')
		res = ft_print_d_i(ap);
	if (fmt == 'u')
		res = ft_print_u(ap);
	if (fmt == 'p')
		res = ft_print_p(ap);
	if (fmt == 'x')
		res = ft_print_lx(ap);
	if (fmt == 'X')
		res = ft_print_ux(ap);
	if (fmt == '%')
		res = write(1, "%", 1);
	return (res);
}

int	ft_printf(const char *fmt, ...)
{
	int		res;
	int		i;
	va_list	ap;

	res = 0;
	i = 0;
	va_start (ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			res += ft_conversions(fmt[i], ap);
		}
		else
		{
			res += write(1, &fmt[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (res);
}
