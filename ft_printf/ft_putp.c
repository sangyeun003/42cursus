/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:12:50 by sangyepa          #+#    #+#             */
/*   Updated: 2023/06/28 17:09:06 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_putp(void *address)
{
	unsigned int	num;
	char			*temp;

	num = 0;
	temp = (char *)address;
	while (*temp)
	{
		if (*temp >= '0' && *temp <= '9')
			num = num * 16 + *temp - '0';
		else
			num = num * 16 + *temp - 'a' + 10;
		temp++;
	}
	ft_putunsignedint_hex_small(num);
}
