/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:41:55 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/11 12:12:24 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ra(t_deque *a)
{
	int	data;

	data = ft_deque_remove_first(a);
	ft_deque_add_last(a, data);
	write(1, "ra\n", 3);
}

void	rb(t_deque *b)
{
	int	data;

	data = ft_deque_remove_first(b);
	ft_deque_add_last(b, data);
	write(1, "rb\n", 3);
}

void	rr(t_deque *a, t_deque *b)
{
	int	data;

	data = ft_deque_remove_first(a);
	ft_deque_add_last(a, data);
	data = ft_deque_remove_first(b);
	ft_deque_add_last(b, data);
	write(1, "rr\n", 3);
}
