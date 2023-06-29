/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:44:18 by sangyepa          #+#    #+#             */
/*   Updated: 2023/06/29 15:50:33 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 출력한 문자의 수를 return
#include	"ft_printf.h"

int	ft_printf(const	char *format, ...)
{
	int		result;
	int		past_result;
	va_list	ap;

	result = 0;
	va_start(ap, format);
	while (*format)
	{
		past_result = result;
		if (*format == '%')
			ft_check(&ap, ++format, &result);
		else
		{
			write(1, format, 1);
			result++;
		}
		if (result < past_result)
		{
			va_end(ap);
			return (-1);
		}
		format++;
	}
	va_end(ap);
	return (result);
}
