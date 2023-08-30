/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:27:08 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/29 20:25:15 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	main(int argc, char *argv[])
{
	t_deque	a;
	t_deque	b;

	ft_deque_init(&a);
	ft_deque_init(&b);

	ft_parsing(argc, argv, &a);
	if (a.count > 0 && !is_sorted(a))
	{
		a_to_b(&a, &b);
	}

	while (!ft_deque_is_empty(&a))
		printf("%d ", ft_deque_remove_first(&a));
	printf("\n\n");

	while (!ft_deque_is_empty(&b))
		printf("%d ", ft_deque_remove_first(&b));
	printf("\n");
	// write(1, "\n", 1);
	return (0);
}
