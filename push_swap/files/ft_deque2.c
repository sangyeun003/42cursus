/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:42:00 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/11 12:04:00 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ft_deque_remove_first(t_deque *pdeq)
{
	t_node	*rnode;
	t_node	*idx_node;
	int		rdata;

	if (ft_deque_is_empty(pdeq))
		ft_error();
	rnode = pdeq->head;
	rdata = rnode->data;
	pdeq->head = pdeq->head->next;
	free(rnode);
	if (pdeq->head == 0)
		pdeq->tail = 0;
	else
		pdeq->head->previous = 0;
	pdeq->count--;
	idx_node = pdeq->head;
	while (idx_node)
	{
		idx_node->index--;
		idx_node = idx_node->next;
	}
	return (rdata);
}

int	ft_deque_remove_last(t_deque *pdeq)
{
	t_node	*rnode;
	int		rdata;

	if (ft_deque_is_empty(pdeq))
		ft_error();
	rnode = pdeq->tail;
	rdata = rnode->data;
	pdeq->tail = pdeq->tail->previous;
	free(rnode);
	if (pdeq->tail == 0)
		pdeq->head = 0;
	else
		pdeq->tail->next = 0;
	pdeq->count--;
	return (rdata);
}
