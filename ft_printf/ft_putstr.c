/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:00:15 by sangyepa          #+#    #+#             */
/*   Updated: 2023/06/29 15:19:57 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putstr(char *s)
{
	int		num;
	char	c;

	num = 0;
	c = 0;
	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		c = *s;
		num += write(1, &c, 1);
		s++;
	}
	return (num);
}
