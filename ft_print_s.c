/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:47:09 by modysseu          #+#    #+#             */
/*   Updated: 2021/11/17 20:36:20 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(va_list	ap)
{
	int		res;
	char	*s;

	if (!ap)
		return (0);
	res = 0;
	s = va_arg(ap, char *);
	if (!s)
		res += write(1, "(null)", 6);
	else
	{
		while (*s)
		{
			res += write(1, s, 1);
			s++;
		}
	}
	return (res);
}
