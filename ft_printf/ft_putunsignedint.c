/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignedint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:09:49 by sangyepa          #+#    #+#             */
/*   Updated: 2023/06/28 17:09:57 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_putunsignedint(unsigned int n)
{
	char	a;

	a = 0;
	if (n < 10)
	{
		a = n + '0';
		write(1, &a, 1);
		return ;
	}
	ft_putunsignedint(n / 10);
	ft_putunsignedint(n % 10);
}
