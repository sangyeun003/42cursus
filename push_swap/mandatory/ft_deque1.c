/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:56:39 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/09 19:42:20 by sangyepa         ###   ########.fr       */
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

void	ft_deque_add_first(t_deque *pdeq1, t_deque *pdeq2, int data)
{
	t_node	*newnode;
	t_node	*idx_node;

	ft_is_overlaping(pdeq1, pdeq2, data);
	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		ft_error(pdeq1, pdeq2);
	newnode->data = data;
	newnode->index = 0;
	newnode->next = pdeq1->head;
	if (ft_deque_is_empty(pdeq1))
		pdeq1->tail = newnode;
	else
		pdeq1->head->previous = newnode;
	newnode->previous = 0;
	pdeq1->head = newnode;
	pdeq1->count++;
	idx_node = pdeq1->head->next;
	while (idx_node)
	{
		idx_node->index++;
		idx_node = idx_node->next;
	}
}

void	ft_deque_add_last(t_deque *pdeq1, t_deque *pdeq2, int data)
{
	t_node	*newnode;

	ft_is_overlaping(pdeq1, pdeq2, data);
	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		ft_error(pdeq1, pdeq2);
	newnode->data = data;
	newnode->index = pdeq1->count;
	newnode->previous = pdeq1->tail;
	if (ft_deque_is_empty(pdeq1))
		pdeq1->head = newnode;
	else
		pdeq1->tail->next = newnode;
	newnode->next = 0;
	pdeq1->tail = newnode;
	pdeq1->count++;
}
