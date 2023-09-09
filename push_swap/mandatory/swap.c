/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:40:46 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/09 19:51:40 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	sa(t_deque *a)
{
	t_node	*temp;

	if (a->count >= 2)
	{
		temp = a->head;
		a->head = a->head->next;
		temp->next = temp->next->next;
		temp->next->previous = temp;
		temp->previous = a->head;
		a->head->next = temp;
		a->head->previous = 0;
		a->head->index--;
		a->head->next->index++;
	}
	temp = 0;
	write(1, "sa\n", 3);
}

void	sb(t_deque *b)
{
	t_node	*temp;

	if (b->count >= 2)
	{
		temp = b->head;
		b->head = b->head->next;
		temp->next = temp->next->next;
		temp->next->previous = temp;
		temp->previous = b->head;
		b->head->next = temp;
		b->head->previous = 0;
		b->head->index--;
		b->head->next->index++;
	}
	temp = 0;
	write(1, "sb\n", 3);
}

void	swap_a(t_deque *a)
{
	t_node	*temp;

	if (a->count >= 2)
	{
		temp = a->head;
		a->head = a->head->next;
		temp->next = temp->next->next;
		temp->next->previous = temp;
		temp->previous = a->head;
		a->head->next = temp;
		a->head->previous = 0;
		a->head->index--;
		a->head->next->index++;
	}
}

void	swap_b(t_deque *b)
{
	t_node	*temp;

	if (b->count >= 2)
	{
		temp = b->head;
		b->head = b->head->next;
		temp->next = temp->next->next;
		temp->next->previous = temp;
		temp->previous = b->head;
		b->head->next = temp;
		b->head->previous = 0;
		b->head->index--;
		b->head->next->index++;
	}
}

void	ss(t_deque *a, t_deque *b)
{
	swap_a(a);
	swap_b(b);
	write(1, "ss\n", 3);
}
