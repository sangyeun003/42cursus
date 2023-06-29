/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:56:55 by sangyepa          #+#    #+#             */
/*   Updated: 2023/06/29 19:31:23 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_putnbr(int n, int *result)
{
	char	a;

	a = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			*result += 11;
			return ;
		}
		n *= -1;
		write(1, "-", 1);
		*result += 1;
	}
	if (n < 10)
	{
		a = n + '0';
		write(1, &a, 1);
		*result += 1;
		return ;
	}
	ft_putnbr(n / 10, result);
	ft_putnbr(n % 10, result);
	return ;
}
