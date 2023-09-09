/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:03:44 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/06 12:24:21 by sangyepa         ###   ########.fr       */
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
	a_command_num = return_index(a, find_location_in_a(a, index_to_data(b, target_b_index)));
	b_command_num = return_index(b, target_b_index);
	if (b_command_num == 1)		// 고민
	{
		sb(b);
		b_command_num--;
	}
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
		ra(a, b);
		a_command_num--;
	}
	while (a_command_num < 0)
	{
		rra(a, b);
		a_command_num++;
	}
	while (b_command_num > 0)
	{
		rb(b, a);
		b_command_num--;
	}
	while (b_command_num < 0)
	{
		rrb(b, a);
		b_command_num++;
	}
	pa(a, b);
}
