/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:37:44 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/20 14:22:43 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_putnbr(int nb)
{
	char			c;
	unsigned int	n;

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
			n = 2147483648;
		else
			n = nb * (-1);
	}
	else
		n = nb;
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
		return ;
	}
	ft_putnbr(n / 10);
	ft_putnbr(n % 10);
	return ;
}
