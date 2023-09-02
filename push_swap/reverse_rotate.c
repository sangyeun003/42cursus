/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:10:43 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/01 16:38:52 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	rra(t_deque *a, t_deque *b)
{
	int	data;

	data = ft_deque_remove_last(a);
	ft_deque_add_first(a, b, data);
	write(1, "rra\n", 4);
}

void	rrb(t_deque *b, t_deque *a)
{
	int	data;

	data = ft_deque_remove_last(b);
	ft_deque_add_first(b, a, data);
	write(1, "rrb\n", 4);
}

void	rrr(t_deque *a, t_deque *b)
{
	int	data;

	data = ft_deque_remove_last(a);
	ft_deque_add_first(a, b, data);
	data = ft_deque_remove_last(b);
	ft_deque_add_first(b, a, data);
	write(1, "rrr\n", 4);
}
