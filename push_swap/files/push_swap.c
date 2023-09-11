/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:27:08 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/11 16:02:19 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

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

void	final_sort(t_deque	*a)
{
	int		min_idx;

	min_idx = find_min_idx(a);
	if (min_idx >= a->count / 2)
	{
		while (min_idx < a->count)
		{
			rra(a);
			min_idx++;
		}
	}
	else
	{
		while (min_idx > 0)
		{
			ra(a);
			min_idx--;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_deque	a;
	t_deque	b;

	if (argc < 2)
		return (0);
	ft_deque_init(&a);
	ft_deque_init(&b);
	ft_parsing(argc, argv, &a);
	if (a.count > 0 && !is_sorted(a))
	{
		a_to_b(&a, &b);
		while (b.count != 0)
			b_to_a(&a, &b);
		final_sort(&a);
	}
	exit(0);
}
