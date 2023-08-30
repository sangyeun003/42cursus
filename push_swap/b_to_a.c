/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:03:44 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/31 05:06:15 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// index화
// 명령어 개수 계산(그리디)
// ra, rb -> rr 최적화

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
	a_command_num = find_location_in_a(a, index_to_data(b, target_b_index));
	b_command_num = find_location_in_b(b, target_b_index);
	printf("a_cnum: %d, b_cnum: %d, b_idx: %d\n", a_command_num, b_command_num, target_b_index);

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
