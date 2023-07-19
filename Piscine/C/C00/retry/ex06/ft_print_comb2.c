/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2_final.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:08:55 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/16 12:49:31 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	ft_print_num(char a, char b);

void	ft_print_num(char a, char b)
{
	write(1, &a, 1);
	write(1, &b, 1);
	return ;
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print_num(a / 10 + '0', a % 10 + '0');
			write(1, " ", 1);
			ft_print_num(b / 10 + '0', b % 10 + '0');
			if (a == 98 && b == 99)
				break ;
			write(1, ", ", 2);
			b++;
		}
		a++;
	}
	return ;
}
