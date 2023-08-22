/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:56:39 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/22 21:27:14 by sangyepa         ###   ########.fr       */
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
	pdeq->head = newnode;
	pdeq->count++;
}

void	ft_deque_add_last(t_deque *pdeq, int data)
{
	t_node	*newnode;

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
	pdeq->tail = newnode;
	pdeq->count++;
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
