/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:02:25 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/16 13:48:49 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_print_combn(int n);
int		promising(char *num, int depth);
void	dfs(char *num, int depth, int n);

int	promising(char *num, int depth)
{
	if (depth == 0 || num[depth - 1] < num[depth])
		return (1);
	return (0);
}

void	ft_print_combn(int n)
{
	char	num[11];
	int		depth;
	int		i;

	i = 0;
	depth = 0;
	dfs(num, depth, n);
}	

void	dfs(char *num, int depth, int n)
{
	int		i;
	char	*s;

	s = "0123456789";
	i = 0;
	if (depth == n)
	{
		write(1, num, n);
		if (num[0] == 10 - n + '0' - 0)
			return ;
		write(1, ", ", 2);
		return ;
	}
	while (i < 10)
	{
		num[depth] = s[i];
		if (promising(num, depth))
			dfs(num, depth + 1, n);
		i++;
	}
}
