/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:20:33 by sangyepa          #+#    #+#             */
/*   Updated: 2023/06/28 17:11:21 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_check(va_list ap, const char *format, int *result)
{
	// va_start(ap, format);
	if (*format == 'c')
		ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		ft_putstr(va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (*format == 'u')
		ft_putunsignedint(va_arg(ap, unsigned int));
	else if (*format == 'p')
		ft_putp(va_arg(ap, void *));
	else if (*format == 'X')
		ft_putunsignedint_hex_large(va_arg(ap, unsigned int));
	else if (*format == 'x')
		ft_putunsignedint_hex_small(va_arg(ap, unsigned int));
	else if (*format == '%')
	{
		write(1, "%", 1);
		(*result)++;
	}
	// va_end(ap);
}
