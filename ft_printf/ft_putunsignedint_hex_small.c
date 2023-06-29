/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignedint_hex_small.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:11:11 by sangyepa          #+#    #+#             */
/*   Updated: 2023/06/29 13:01:22 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include        "ft_printf.h"

void	ft_putunsignedint_hex_small(unsigned int nbr, int *result)
{
	char	n;

	if (nbr < 16)
	{
		if (nbr < 10)
			n = nbr + '0';
		else
			n = nbr + 87;
		write(1, &n, 1);
		*result += 1;
		return ;
	}
	ft_putunsignedint_hex_small(nbr / 16, result);
	ft_putunsignedint_hex_small(nbr % 16, result);
	return ;
}
