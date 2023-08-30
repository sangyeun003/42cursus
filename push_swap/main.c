/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:27:08 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/31 05:15:38 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	main(int argc, char *argv[])
{
	t_deque	a;
	t_deque	b;
	t_node	*node_a;
	t_node	*node_b;

	ft_deque_init(&a);
	ft_deque_init(&b);

	ft_parsing(argc, argv, &a);

	if (a.count > 0 && !is_sorted(a))
		a_to_b(&a, &b);

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
	
	// printf("\n\n");
	
	// while (b.count != 0)
	{
		b_to_a(&a, &b);
		while (!is_sorted(a))	// a는 항상 정렬된 상태!
			ra(&a);
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

	// while (!ft_deque_is_empty(&a))
	// 	printf("index: %d, data: %d\n", a.head->index, ft_deque_remove_first(&a));
	// printf("\n\n");

	// while (!ft_deque_is_empty(&b))
	// 	printf("index: %d, data: %d\n", b.head->index, ft_deque_remove_first(&b));
	// printf("\n");
	// write(1, "\n", 1);
	return (0);
}
