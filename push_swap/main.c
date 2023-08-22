/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:27:08 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/22 20:23:15 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	main(int argc, char *argv[])
{
	t_deque	a;
	t_deque	b;

	ft_deque_init(&a);
	ft_deque_init(&b);
// ra
	ft_parsing(argc, argv, &a);
	ra(&a);
	while (!ft_deque_is_empty(&a))
		printf("%d ", ft_deque_remove_first(&a));
	printf("\n");
// rra
	ft_parsing(argc, argv, &a);
	rra(&a);
	while (!ft_deque_is_empty(&a))
		printf("%d ", ft_deque_remove_first(&a));
	printf("\n");
// rr
	ft_parsing(argc, argv, &a);
	ft_parsing(argc, argv, &b);
	rr(&a, &b);
	while (!ft_deque_is_empty(&a))
		printf("%d ", ft_deque_remove_first(&a));
	printf("\n");
	while (!ft_deque_is_empty(&b))
		printf("%d ", ft_deque_remove_first(&b));
	printf("\n");
// rrr
	ft_parsing(argc, argv, &a);
	ft_parsing(argc, argv, &b);
	rrr(&a, &b);
	while (!ft_deque_is_empty(&a))
		printf("%d ", ft_deque_remove_first(&a));
	printf("\n");
	while (!ft_deque_is_empty(&b))
		printf("%d ", ft_deque_remove_first(&b));
	printf("\n");
	return (0);
}
