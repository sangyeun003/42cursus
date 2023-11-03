/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:56:55 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/01 00:07:04 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_put_integer(int n, int *result)
{
	int	check;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			check = write(1, "-2147483648", 11);
			if (check < 0)
				*result = check;
			else
				*result += check;
			return ;
		}
		n *= -1;
		check = write(1, "-", 1);
		if (check < 0)
		{
			*result = check;
			return ;
		}
		else
			*result += check;
	}
	ft_putunsignedint((unsigned int)n, result);
	return ;
}
