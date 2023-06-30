/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignedint_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:47:52 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/01 00:03:53 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include        "ft_printf.h"

void	ft_putunsignedint_hex(unsigned int nbr, int *result, char x)
{
	char	n;
	int		check;

	if (nbr < 16)
	{
		if (nbr < 10)
			n = nbr + '0';
		else
		{
			if (x == 'X')
				n = nbr + 55;
			else if (x == 'x')
				n = nbr + 87;
		}
		check = write(1, &n, 1);
		if (check < 0)
			*result = check;
		else
			*result += check;
		return ;
	}
	ft_putunsignedint_hex(nbr / 16, result, x);
	if (*result < 0)
		return ;
	ft_putunsignedint_hex(nbr % 16, result, x);
}
