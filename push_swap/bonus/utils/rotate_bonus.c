/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:41:55 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/09 22:47:05 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	ra(t_deque *a, t_deque *b)
{
	int	data;

	data = ft_deque_remove_first(a, b);
	ft_deque_add_last(a, b, data);
}

void	rb(t_deque *b, t_deque *a)
{
	int	data;

	data = ft_deque_remove_first(b, a);
	ft_deque_add_last(b, a, data);
}

void	rr(t_deque *a, t_deque *b)
{
	int	data;

	data = ft_deque_remove_first(a, b);
	ft_deque_add_last(a, b, data);
	data = ft_deque_remove_first(b, a);
	ft_deque_add_last(b, a, data);
}
