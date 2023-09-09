/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:27:08 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/06 12:17:38 by sangyepa         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_deque	a;
	t_deque	b;
	// t_node	*node_a;
	// t_node	*node_b;
	
	if (argc < 2)
		return (0);
	ft_deque_init(&a);
	ft_deque_init(&b);
	ft_parsing(argc, argv, &a, &b);

	if (a.count > 0 && !is_sorted(a))
	{
		a_to_b(&a, &b);
		while (b.count != 0)
			b_to_a(&a, &b);
		final_sort(&a, &b);
	}
	// node_a = a.head;
	// node_b = b.head;
	// while (node_a)
	// {
	// 	printf("index: %d, data: %d\n", node_a->index, node_a->data);
	// 	node_a = node_a->next;
	// }
	// printf("\n\n");
	// while (node_b)
	// {
	// 	printf("index: %d, data: %d\n", node_b->index, node_b->data);
	// 	node_b = node_b->next;
	// }
	// printf("==================\n\n");
	
	// node_a = a.head;
	// while (node_a)
	// {
	// 	printf("index: %d, data: %d\n", node_a->index, node_a->data);
	// 	node_a = node_a->next;
	// }
	system("leaks push_swap");
	return (0);
}
