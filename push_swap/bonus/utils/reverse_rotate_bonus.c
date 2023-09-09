/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:10:43 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/09 22:47:14 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	rra(t_deque *a, t_deque *b)
{
	int	data;

	data = ft_deque_remove_last(a, b);
	ft_deque_add_first(a, b, data);
}

void	rrb(t_deque *b, t_deque *a)
{
	int	data;

	data = ft_deque_remove_last(b, a);
	ft_deque_add_first(b, a, data);
}

void	rrr(t_deque *a, t_deque *b)
{
	int	data;

	data = ft_deque_remove_last(a, b);
	ft_deque_add_first(a, b, data);
	data = ft_deque_remove_last(b, a);
	ft_deque_add_first(b, a, data);
}
