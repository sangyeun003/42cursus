/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:49:14 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/23 15:21:37 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	double_check(char *queen, int i)
{
	int	cmp;
	int	j;

	cmp = 0;
	j = 1;
	if (i == 0)
		return (1);
	while (cmp < i)
		if (queen[i] == queen[cmp++])
			return (0);
	cmp = i - 1;
	while (cmp >= 0 && (queen[i] - j >= '0'))
		if (queen[i] - j++ == queen[cmp--])
			return (0);
	j = 1;
	cmp = i - 1;
	while (cmp >= 0 && (queen[i] + j <= '9'))
		if (queen[i] + j++ == queen[cmp--])
			return (0);
	return (1);
}

void	find_case(char *queen, int i, int *count)
{
	int	num;

	num = 0;
	if (i == 10)
	{
		write(1, queen, 10);
		write(1, "\n", 1);
		(*count)++;
		return ;
	}
	while (num < 10)
	{
		queen[i] = num + '0';
		if (double_check(queen, i))
			find_case(queen, i + 1, count);
		num++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		count;
	char	queen[11];

	find_case(queen, 0, &count);
	return (count);
}
