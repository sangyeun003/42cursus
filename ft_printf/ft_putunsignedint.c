/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignedint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:09:49 by sangyepa          #+#    #+#             */
/*   Updated: 2023/06/29 13:01:35 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_putunsignedint(unsigned int n, int *result)
{
	char	a;

	a = 0;
	if (n < 10)
	{
		a = n + '0';
		write(1, &a, 1);
		*result += 1;
		return ;
	}
	ft_putunsignedint(n / 10, result);
	ft_putunsignedint(n % 10, result);
}
