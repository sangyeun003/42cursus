/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:42:00 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/09 22:36:22 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

int	ft_deque_remove_first(t_deque *pdeq1, t_deque *pdeq2)
{
	t_node	*rnode;
	t_node	*idx_node;
	int		rdata;

	if (ft_deque_is_empty(pdeq1))
		ft_error(pdeq1, pdeq2);
	rnode = pdeq1->head;
	rdata = rnode->data;
	pdeq1->head = pdeq1->head->next;
	free(rnode);
	if (pdeq1->head == 0)
		pdeq1->tail = 0;
	else
		pdeq1->head->previous = 0;
	pdeq1->count--;
	idx_node = pdeq1->head;
	while (idx_node)
	{
		idx_node->index--;
		idx_node = idx_node->next;
	}
	return (rdata);
}

int	ft_deque_remove_last(t_deque *pdeq1, t_deque *pdeq2)
{
	t_node	*rnode;
	int		rdata;

	if (ft_deque_is_empty(pdeq1))
		ft_error(pdeq1, pdeq2);
	rnode = pdeq1->tail;
	rdata = rnode->data;
	pdeq1->tail = pdeq1->tail->previous;
	free(rnode);
	if (pdeq1->tail == 0)
		pdeq1->head = 0;
	else
		pdeq1->tail->next = 0;
	pdeq1->count--;
	return (rdata);
}
