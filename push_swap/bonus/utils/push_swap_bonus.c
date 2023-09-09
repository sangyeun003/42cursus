/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:27:08 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/09 22:37:12 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

int	find_min_idx(t_deque *pdeq)
{
	int		min;
	int		min_idx;
	t_node	*node;

	min = pdeq->head->data;
	min_idx = pdeq->head->index;
	node = pdeq->head;
	while (node)
	{
		if (node->data < min)
		{
			min = node->data;
			min_idx = node->index;
		}
		node = node->next;
	}
	if (node)
		free(node);
	return (min_idx);
}

void	final_sort(t_deque	*a, t_deque *b)
{
	int		min_idx;

	min_idx = find_min_idx(a);
	if (min_idx >= a->count / 2)
	{
		while (min_idx < a->count)
		{
			rra(a, b);
			min_idx++;
		}
	}
	else
	{
		while (min_idx > 0)
		{
			ra(a, b);
			min_idx--;
		}
	}
}
