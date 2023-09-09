/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:03:44 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/09 22:36:12 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

int	index_to_data(t_deque *pdeq, int index)
{
	t_node	*node;

	node = pdeq->head;
	while (index-- > 0)
		node = node->next;
	return (node->data);
}

void	reverse_a(t_deque *a, t_deque *b, int *a_cmd_num)
{
	while (*a_cmd_num)
	{
		if (*a_cmd_num > 0)
		{
			ra(a, b);
			(*a_cmd_num)--;
		}
		else
		{
			rra(a, b);
			(*a_cmd_num)++;
		}
	}
}

void	reverse_b(t_deque *a, t_deque *b, int *b_cmd_num)
{
	while (*b_cmd_num)
	{
		if (*b_cmd_num > 0)
		{
			rb(b, a);
			(*b_cmd_num)--;
		}
		else
		{
			rrb(b, a);
			(*b_cmd_num)++;
		}
	}
}

void	reverse_together(t_deque *a, t_deque *b, int *a_cmd_num, int *b_cmd_num)
{
	while (*a_cmd_num && *b_cmd_num
		&& (*a_cmd_num > 0 && *b_cmd_num > 0))
	{
		rr(a, b);
		(*a_cmd_num)--;
		(*b_cmd_num)--;
	}
	while (*a_cmd_num && *b_cmd_num
		&& (*a_cmd_num < 0 && *b_cmd_num < 0))
	{
		rrr(a, b);
		(*a_cmd_num)++;
		(*b_cmd_num)++;
	}
}

void	b_to_a(t_deque *a, t_deque *b)
{
	int	target_b_index;
	int	a_cmd_num;
	int	b_cmd_num;

	target_b_index = greedy(a, b);
	a_cmd_num = return_index(a,
			find_location_in_a(a, index_to_data(b, target_b_index)));
	b_cmd_num = return_index(b, target_b_index);
	reverse_together(a, b, &a_cmd_num, &b_cmd_num);
	reverse_a(a, b, &a_cmd_num);
	reverse_b(a, b, &b_cmd_num);
	pa(a, b);
}
