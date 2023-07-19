/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:07:11 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/27 22:48:13 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"func.h"

int	ft_cal(int a, char c, int b)
{
	int	(*f[5])(int, int);

	f[0] = (*ft_sum);
	f[1] = (*ft_sub);
	f[2] = (*ft_mul);
	f[3] = (*ft_div);
	f[4] = (*ft_modulo);
	if (c == '+')
		return (f[0](a, b));
	else if (c == '-')
		return (f[1](a, b));
	else if (c == '*')
		return (f[2](a, b));
	else if (c == '/')
		return (f[3](a, b));
	else if (c == '%')
		return (f[4](a, b));
	return (0);
}
