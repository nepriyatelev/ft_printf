/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:48:31 by modysseu          #+#    #+#             */
/*   Updated: 2021/11/18 15:58:42 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_print_c(va_list	ap);
int		ft_print_s(va_list	ap);
int		ft_print_d_i(va_list	ap);
int		ft_print_u(va_list	ap);
int		ft_print_p(va_list	ap);
int		ft_print_lx(va_list	ap);
int		ft_print_ux(va_list	ap);

int		ft_printf(const char *fmt, ...);

#endif
