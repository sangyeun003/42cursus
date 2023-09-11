/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:56:39 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/11 12:02:00 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_deque_init(t_deque *pdeq)
{
	pdeq->head = 0;
	pdeq->tail = 0;
	pdeq->count = 0;
}

int	ft_deque_is_empty(t_deque *pdeq)
{
	if (pdeq->head == 0)
		return (TRUE);
	else
		return (FALSE);
}

void	ft_deque_add_first(t_deque *pdeq, int data)
{
	t_node	*newnode;
	t_node	*idx_node;

	ft_is_overlaping(pdeq, data);
	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		ft_error();
	newnode->data = data;
	newnode->index = 0;
	newnode->next = pdeq->head;
	if (ft_deque_is_empty(pdeq))
		pdeq->tail = newnode;
	else
		pdeq->head->previous = newnode;
	newnode->previous = 0;
	pdeq->head = newnode;
	pdeq->count++;
	idx_node = pdeq->head->next;
	while (idx_node)
	{
		idx_node->index++;
		idx_node = idx_node->next;
	}
}

void	ft_deque_add_last(t_deque *pdeq, int data)
{
	t_node	*newnode;

	ft_is_overlaping(pdeq, data);
	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		ft_error();
	newnode->data = data;
	newnode->index = pdeq->count;
	newnode->previous = pdeq->tail;
	if (ft_deque_is_empty(pdeq))
		pdeq->head = newnode;
	else
		pdeq->tail->next = newnode;
	newnode->next = 0;
	pdeq->tail = newnode;
	pdeq->count++;
}
