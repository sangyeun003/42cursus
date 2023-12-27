/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:35:25 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/27 22:14:47 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/philo.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result > 9223372036854775807 && sign == 1)
		return (-1);
	else if (result - 1 > 9223372036854775807 && sign == -1)
		return (0);
	return (sign * result);
}
