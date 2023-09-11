/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:10:43 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/11 15:55:10 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	rra(t_deque *a)
{
	int	data;

	data = ft_deque_remove_last(a);
	ft_deque_add_first(a, data);
}

void	rrb(t_deque *b)
{
	int	data;

	data = ft_deque_remove_last(b);
	ft_deque_add_first(b, data);
}

void	rrr(t_deque *a, t_deque *b)
{
	int	data;

	data = ft_deque_remove_last(a);
	ft_deque_add_first(a, data);
	data = ft_deque_remove_last(b);
	ft_deque_add_first(b, data);
}
