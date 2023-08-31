/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:03:44 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/31 23:27:27 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	index_to_data(t_deque *pdeq, int index)
{
	t_node	*node;

	node = pdeq->head;
	while (index-- > 0)
		node = node->next;
	return (node->data);
}

void	b_to_a(t_deque *a, t_deque *b)
{
	int	target_b_index;
	int	a_command_num;
	int	b_command_num;

	target_b_index = greedy(a, b);
	// printf("target_b: %d\n", target_b_index);
	a_command_num = return_index(a, find_location_in_a(a, index_to_data(b, target_b_index)));
	b_command_num = return_index(b, target_b_index);
	// printf("a_cmd: %d, b_cmd: %d\n", a_command_num, b_command_num);
	// if (a_command_num == 1 && b_command_num == 1)
	// {
	// 	ss(a, b);
	// 	a_command_num--;
	// 	b_command_num--;
	// }
	// if (a_command_num == 1)
	// {
	// 	sa(a);
	// 	a_command_num--;
	// }
	// if (b_command_num == 1)
	// {
	// 	sb(b);
	// 	b_command_num--;
	// }
	while (a_command_num && b_command_num && (a_command_num > 0 && b_command_num > 0))
	{
		rr(a, b);
		a_command_num--;
		b_command_num--;
	}
	while (a_command_num && b_command_num && (a_command_num < 0 && b_command_num < 0))
	{
		rrr(a, b);
		a_command_num++;
		b_command_num++;
	}
	while (a_command_num > 0)
	{
		ra(a);
		a_command_num--;
	}
	while (a_command_num < 0)
	{
		rra(a);
		a_command_num++;
	}
	while (b_command_num > 0)
	{
		rb(b);
		b_command_num--;
	}
	while (b_command_num < 0)
	{
		rrb(b);
		b_command_num++;
	}
	pa(a, b);
}
