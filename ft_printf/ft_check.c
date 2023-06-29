/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:20:33 by sangyepa          #+#    #+#             */
/*   Updated: 2023/06/29 15:48:11 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_check(va_list *ap, const char *format, int *result)
{
	if (*format == 'c')
		*result += ft_putchar(va_arg(*ap, int));
	else if (*format == 's')
		*result += ft_putstr(va_arg(*ap, char *));
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(*ap, int), result);
	else if (*format == 'u')
		ft_putunsignedint(va_arg(*ap, unsigned int), result);
	else if (*format == 'p')
	{
		write(1, "0x", 2);
		*result += 2;
		ft_putp((unsigned long long)va_arg(*ap, void *), result);
	}
	else if (*format == 'X')
		ft_putunsignedint_hex_large(va_arg(*ap, unsigned int), result);
	else if (*format == 'x' || *format == 'p')
		ft_putunsignedint_hex_small(va_arg(*ap, unsigned int), result);
	else if (*format == '%')
	{
		write(1, "%", 1);
		*result += 1;
	}
}
