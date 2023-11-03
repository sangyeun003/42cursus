/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignedint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:09:49 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/01 00:04:13 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_putunsignedint(unsigned int n, int *result)
{
	char	a;
	int		check;

	a = 0;
	if (n < 10)
	{
		a = n + '0';
		check = write(1, &a, 1);
		if (check < 0)
			*result = check;
		else
			*result += check;
		return ;
	}
	ft_putunsignedint(n / 10, result);
	if (*result < 0)
		return ;
	ft_putunsignedint(n % 10, result);
	return ;
}
