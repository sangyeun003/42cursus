/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:20:33 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/01 00:01:50 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_check(va_list *ap, const char *format, int *result)
{
	int	check;

	if (*format == 'c')
		*result += ft_putchar(va_arg(*ap, int));
	else if (*format == 's')
		*result += ft_putstr(va_arg(*ap, char *));
	else if (*format == 'd' || *format == 'i')
		ft_put_integer(va_arg(*ap, int), result);
	else if (*format == 'u')
		ft_putunsignedint(va_arg(*ap, unsigned int), result);
	else if (*format == 'p')
	{
		check = write(1, "0x", 2);
		if (check == 2)
		{
			*result += check;
			ft_putp((unsigned long long)va_arg(*ap, void *), result);
		}
		else
			*result = check;
	}
	else if (*format == 'X' || *format == 'x')
		ft_putunsignedint_hex(va_arg(*ap, unsigned int), result, *format);
	else if (*format == '%')
		*result += write(1, "%", 1);
}
