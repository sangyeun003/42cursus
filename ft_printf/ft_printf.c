/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:44:18 by sangyepa          #+#    #+#             */
/*   Updated: 2023/06/28 17:15:18 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 출력한 문자의 수를 return
#include	"ft_printf.h"

int	ft_printf(const	char *format, ...)
{
	int		*result;
	va_list	ap;

	*result = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 0)
				break ;
			if (*format == 'c')
				ft_putchar(va_arg(ap, char));
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
				write(1, "%", 1);
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (*result);
}
