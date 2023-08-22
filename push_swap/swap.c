/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:40:46 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/22 19:39:15 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	sa(t_deque *a)
{
	t_node	*temp;

	temp = a->head;
	a->head = a->head->next;
	temp->next = temp->next->next;
	temp->next->previous = temp;
	head->next = temp;
	head->previous = 0;
	write(1, "sa\n", 3);
}

void	sb(t_deque *b)
{
	t_node	*temp;

	temp = b->head;
	b->head = b->head->next;
	temp->next = temp->next->next;
	temp->next->previous = temp;
	head->next = temp;
	head->previous = 0;
	write(1, "sb\n", 3);
}

void	ss(t_deque *a, t_deque *b)
{
	sa(a);
	sb(b);
}
