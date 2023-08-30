/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:56:39 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/31 03:04:53 by sangyepa         ###   ########.fr       */
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

	ft_is_overlaping(pdeq, data);
	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		ft_error(pdeq);
	newnode->data = data;
	newnode->next = pdeq->head;
	if (ft_deque_is_empty(pdeq))
		pdeq->tail = newnode;
	else
		pdeq->head->previous = newnode;
	newnode->previous = 0;
	newnode->index = pdeq->count + 1;
	pdeq->head = newnode;
	pdeq->count++;
}

void	ft_deque_add_last(t_deque *pdeq, int data)
{
	t_node	*newnode;
	t_node	*idx_node;

	ft_is_overlaping(pdeq, data);
	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		ft_error(pdeq);
	newnode->data = data;
	newnode->previous = pdeq->tail;
	if (ft_deque_is_empty(pdeq))
		pdeq->head = newnode;
	else
		pdeq->tail->next = newnode;
	newnode->next = 0;
	newnode->index = 0;
	pdeq->tail = newnode;
	pdeq->count++;
	idx_node = pdeq->tail;
	while (idx_node)
	{
		idx_node->index++;
		idx_node = idx_node->previous;
	}
}

int	ft_deque_remove_first(t_deque *pdeq)
{
	t_node	*rnode;
	int		rdata;

	if (ft_deque_is_empty(pdeq))
		ft_error(pdeq);
	rnode = pdeq->head;
	rdata = rnode->data;
	pdeq->head = pdeq->head->next;
	free(rnode);
	if (pdeq->head == 0)
		pdeq->tail = 0;
	else
		pdeq->head->previous = 0;
	pdeq->count--;
	return (rdata);
}

int	ft_deque_remove_last(t_deque *pdeq)
{
	t_node	*rnode;
	t_node	*idx_node;
	int		rdata;

	if (ft_deque_is_empty(pdeq))
		ft_error(pdeq);
	rnode = pdeq->tail;
	rdata = rnode->data;
	pdeq->tail = pdeq->tail->previous;
	free(rnode);
	if (pdeq->tail == 0)
		pdeq->head = 0;
	else
		pdeq->tail->next = 0;
	pdeq->count--;
	idx_node = pdeq->head;
	while (idx_node)
	{
		idx_node->index--;
		idx_node = idx_node->next;
	}
	return (rdata);
}

int	ft_deque_get_first(t_deque *pdeq)
{
	if (ft_deque_is_empty(pdeq))
		ft_error(pdeq);
	return (pdeq->head->data);
}

int	ft_deque_get_last(t_deque *pdeq)
{
	if (ft_deque_is_empty(pdeq))
		ft_error(pdeq);
	return (pdeq->tail->data);
}
