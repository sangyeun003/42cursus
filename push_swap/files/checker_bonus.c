/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:30:32 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/11 16:12:07 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	execute_cmd(char *cmd, t_deque *a, t_deque *b)
{
	if (!ft_strcmp(cmd, "sa\n"))
		sa(a);
	else if (!ft_strcmp(cmd, "sb\n"))
		sb(b);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(cmd, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(cmd, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(cmd, "ra\n"))
		ra(a);
	else if (!ft_strcmp(cmd, "rb\n"))
		rb(b);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(cmd, "rra\n"))
		rra(a);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr(a, b);
	else
		ft_error();
}

int	main(int argc, char **argv)
{
	t_deque	a;
	t_deque	b;
	char	*cmd;

	if (argc < 2)
		return (0);
	ft_deque_init(&a);
	ft_deque_init(&b);
	ft_parsing(argc, argv, &a);
	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		execute_cmd(cmd, &a, &b);
		free(cmd);
	}
	if (is_sorted(a) && b.count == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(0);
}
