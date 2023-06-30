/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:00:15 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/01 00:03:42 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putstr(char *s)
{
	int		num;
	int		check;
	char	c;

	num = 0;
	c = 0;
	if (s == 0)
	{
		check = write(1, "(null)", 6);
		return (check);
	}
	while (*s)
	{
		c = *s;
		check = write(1, &c, 1);
		if (check < 0)
			return (check);
		else
			num += check;
		s++;
	}
	return (num);
}
