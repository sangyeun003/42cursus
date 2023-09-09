/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 03:18:16 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/09 19:57:47 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	find_max_idx(t_deque *pdeq)
{
	int		max;
	int		max_idx;
	t_node	*node;

	max = pdeq->head->data;
	max_idx = pdeq->head->index;
	node = pdeq->head;
	while (node)
	{
		if (node->data > max)
		{
			max = node->data;
			max_idx = node->index;
		}
		node = node->next;
	}
	if (node)
		free(node);
	return (max_idx);
}

int	find_location_in_a(t_deque *a, int b_num)
{
	t_node	*node;

	if (b_num < index_to_data(a, find_min_idx(a)))
		return (find_min_idx(a));
	node = a->head;
	while (node)
	{
		if (node == a->head && node->data > b_num && a->tail->data < b_num)
			break ;
		else if (node->previous)
		{
			if (node->data > b_num && node->previous->data < b_num)
				break ;
		}
		node = node->next;
	}
	if (!node) // a_max보다 큰 수
	{
		if (a->head->index == find_min_idx(a)
			&& a->tail->index == find_max_idx(a))
			return (0);
		if (find_max_idx(a) + 1 == find_min_idx(a))
			return (find_min_idx(a));
	}
	return (node->index);
}

int	return_index(t_deque *pdeq, int index)
{
	if (index >= pdeq->count / 2)
		return (index - pdeq->count);
	return (index);
}

int	cal_total_command_num(int a_command_num, int b_command_num)
{
	if (a_command_num < 0)
		a_command_num *= (-1);
	if (b_command_num < 0)
		b_command_num *= (-1);
	return (a_command_num + b_command_num);
}

int	greedy(t_deque *a, t_deque *b)
{
	t_node	*node;
	int		target_b_index;
	int		min_total_command_num;

	node = b->head;
	target_b_index = 0;
	min_total_command_num
		= cal_total_command_num(find_location_in_a(a, b->head->data), 0);
	while (node && b->count >= 2)
	{
		if (min_total_command_num
			> cal_total_command_num(return_index(a, find_location_in_a
					(a, node->data)), return_index(b, node->index)))
		{
			min_total_command_num
				= cal_total_command_num(return_index(a, find_location_in_a
						(a, node->data)), return_index(b, node->index));
			target_b_index = node->index;
		}
		node = node->next;
	}
	if (!node)
		free(node);
	return (target_b_index);
}
