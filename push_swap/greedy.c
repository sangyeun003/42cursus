/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 03:18:16 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/31 05:09:46 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	find_location_in_a(t_deque *a, int b_num)
{
	t_node	*node;

	node = a->head;
	while (node)
	{
		if (node->data > b_num)
			break ;
		node = node->next;
	}
	if (node->index >= a->count / 2)
		return (node->index - a->count);
	return (node->index);
}

int	find_location_in_b(t_deque *b, int b_index)
{
	if (b_index > b->count / 2)
		return (b_index - b->count);
	return (b_index);
}

int	cal_total_command_num(int a_command_num, int b_command_num)
{
	if (a_command_num < 0)
		a_command_num *= -1;
	if (b_command_num < 0)
		b_command_num *= -1;
	return (a_command_num + b_command_num);
}

int	greedy(t_deque *a, t_deque *b)
{
	t_node	*node;
	int		target_b_index;
	int		min_total_command_num;

	node = b->head;
	target_b_index = 0;
	min_total_command_num = find_location_in_a(a, b->head->data);
	while (node && b->count >= 2)
	{
		if (min_total_command_num >
				cal_total_command_num(find_location_in_a(a, node->data),
									find_location_in_b(b, node->index)))
		{
			min_total_command_num =
				cal_total_command_num(find_location_in_a(a, node->data),
									find_location_in_b(b, node->index));
			target_b_index = node->index;
		}
		node = node->next;
	}
	return (target_b_index);
}
