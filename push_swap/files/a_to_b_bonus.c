/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:09:49 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/11 15:00:05 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

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

void	a_to_b_by_pivot(t_deque *a, t_deque *b, int pivot)
{
	int	num_a;

	num_a = a->count;
	while (num_a-- > 0 && a->count > 3)
	{
		if (a->head->data <= pivot)
			pb(a, b);
		else
			ra(a);
	}
}

void	a_to_b(t_deque *a, t_deque *b)
{
	int		pivot1;
	int		pivot2;
	int		max;

	if (a->count > 3)
	{
		make_pivot(a, &pivot1, &pivot2, &max);
		a_to_b_by_pivot(a, b, pivot1);
		a_to_b_by_pivot(a, b, pivot2);
		while (a->count > 3)
			pb(a, b);
	}
	if (a->count == 3)
		sort_3(a);
	else if (a->count == 2)
		sort_2(a);
}
