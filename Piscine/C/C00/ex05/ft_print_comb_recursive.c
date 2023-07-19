/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb_recursive.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:11:42 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/16 14:52:02 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_print_comb(void);
void	dfs(char *s, int depth);
int		promising(char *num, int depth);

int	promising(char *num, int depth)
{
	if (depth == 0 || num[depth] > num[depth - 1])
		return (1);
	return (0);
}

void	dfs(char *s, int depth)
{
	int	n;
	int	i;

	i = 0;
	n = 3;
	if (depth == n)
	{
		write(1, s, 3);
		if (s[0] == '7')
			return ;
		write(1, ", ", 2);
		return ;
	}
	while (i < 10)
	{
		s[depth] = i + '0' - 0;
		if (promising(s, depth))
			dfs(s, depth + 1);
		i++;
	}
}

void	ft_print_comb(void)
{
	char	s[3];

	dfs(s, 0);
}
