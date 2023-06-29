/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:12:50 by sangyepa          #+#    #+#             */
/*   Updated: 2023/06/29 14:39:17 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_putp(unsigned long long nbr, int *result)
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
	ft_putp(nbr / 16, result);
	ft_putp(nbr % 16, result);
	return ;
}
