/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:10:12 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/29 15:43:35 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	is_sorted(t_deque deq)
{
	t_node	*node;

	node = deq.head;
	while (node->next)
	{
		if (node->data >= node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}
