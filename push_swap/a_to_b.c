/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:09:49 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/31 05:37:08 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	make_pivot(t_deque *a, int *pivot1, int *pivot2, int *max)
{
	t_node	*node;
	int		min;

	min = a->head->data;
	*max = a->head->data;
	node = a->head->next;
	while (node)
	{
		if (node->data < min)
			min = node->data;
		if (node->data > *max)
			*max = node->data;
		node = node->next;
	}
	*pivot1 = min + (*max - min) / 3;
	*pivot2 = *max - (*max - min) / 3;
}

void	a_to_b(t_deque *a, t_deque *b)
{
	int		pivot1;
	int		pivot2;
	int		max;
	int		num_a;

	if (a->count > 3)
	{
		make_pivot(a, &pivot1, &pivot2, &max);
		num_a = a->count;
		while (num_a-- > 0 && a->count > 1)
		{
			if (a->head->data <= pivot1)
				pb(a, b);
			else
				ra(a);
		}
		num_a = a->count;
		while (num_a-- > 0 && a->count > 1)
		{
			if (a->head->data <= pivot2)
				pb(a, b);
			else
				ra(a);
		}
		while (a->count > 3)
		{
			if (a->head->data != max)
				pb(a, b);
			else
				ra(a);
		}
	}
	if (a->count == 3)
		sort_3(a);
	else if (a->count == 2)
		sort_2(a);
}
