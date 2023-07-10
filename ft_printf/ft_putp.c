/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:12:50 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/10 18:49:47 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_putp(uintptr_t nbr, int *result)
{
	char	n;
	int		check;

	if (nbr < 16)
	{
		if (nbr < 10)
			n = nbr + '0';
		else
			n = nbr + 87;
		check = write(1, &n, 1);
		if (check < 0)
			*result = check;
		else
			*result += check;
		return ;
	}
	ft_putp(nbr / 16, result);
	if (*result < 0)
		return ;
	ft_putp(nbr % 16, result);
	return ;
}
