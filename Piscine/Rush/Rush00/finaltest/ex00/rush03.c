/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:09:08 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/11 16:27:32 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	rush(int x, int y);
void	first(int x, int j);
void	mid(int x, int j);
void	ft_putchar(char c);

void	first(int x, int j)
{
	ft_putchar('A');
	while (j < x - 2)
	{
		ft_putchar('B');
		j++ ;
	}
	if (x > 1)
		ft_putchar('C');
}

void	mid(int x, int j)
{
	ft_putchar('B');
	while (j < x - 2)
	{
		ft_putchar(' ');
		j++ ;
	}
	if (x > 1)
		ft_putchar('B');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
	{
		write(1, "Error\n", 6);
		return ;
	}
	i = 0;
	while (i < y)
	{
		j = 0;
		if (i == 0 || i == y - 1)
			first(x, j);
		else
			mid(x, j);
		ft_putchar('\n');
		i++ ;
	}
}
