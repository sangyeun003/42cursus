/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:44:18 by sangyepa          #+#    #+#             */
/*   Updated: 2023/06/28 12:16:26 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 출력한 문자의 수를 return
#include	"ft_printf.h"

int	ft_printf(const	char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 0)
				break ;
			if (*format == 'c')
				ft_putchar_fd(va_arg(ap, char), 1);
			else if (*format == 's')
				ft_putstr_fd(va_arg(ap, char*), 1);
			else if (*format == 'd' || *format == 'i')
				ft_putnbr_fd(va_arg(ap, int), 1);
			else if (*format == 'u')
				ft_putunsignedint(va_arg(ap, unsigned int));
			// else if (*format == 'p')
			// 	ft_putp(va_arg(ap, void*));
			else if (*format == 'X')
				ft_putunsignedint_hex_large(va_arg(ap, unsigned int));
			else if (*format == 'x')
				ft_putunsignedint_hex_small(va_arg(ap, unsigned int));
			format++;
		}
		else
		{
			write(1, format, 1);
			format++;
		}
	}
	va_end(ap);
	return (0);
}
